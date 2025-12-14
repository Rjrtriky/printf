/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 13:51:23 by rjuarez-          #+#    #+#             */
/*   Updated: 2025/12/11 15:03:51 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str);
void	*ft_bzero(void *ptr, size_t len);
void	*ft_calloc(size_t num, size_t size);
char	ft_conver_digital(unsigned char c);
char	*ft_strtoup(char **text);

/*FT_STRLEN
 * @def Calculates the length of a string (number of characters before '\0').
 *
 * @param
 *      {string} *str - string whose length is to be calculated.
 *
 * @returns {number}
 *      OK - Length of the string as size_t.
 *      KO - Undefined if str is NULL (no control implemented).
 */
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*FT_BZERO
 * @def Sets a block of memory to zero.
 *
 * @param
 *      {pointer} *ptr - pointer to the memory block to be cleared.
 *      {number} len - number of bytes to set to zero.
 *
 * @returns {pointer}
 *      OK - Returns the same pointer received, now zeroed.
 *      KO - Undefined if ptr is NULL (no control implemented).
 */
void	*ft_bzero(void *ptr, size_t len)
{
	unsigned char	*aux_ptr;
	size_t			i;

	i = 0;
	aux_ptr = ptr;
	while (i < len)
	{
		*aux_ptr = 0;
		aux_ptr++;
		i++;
	}
	return (ptr);
}

/*FT_CALLOC
 * @def Allocates memory for an array of elements and initializes it to zero.
 *
 * @param
 *      {number} num - number of elements to allocate.
 *      {number} size - size of each element in bytes.
 *
 * @returns {pointer}
 *      OK - Pointer to the allocated and zero-initialized memory.
 *      KO - NULL if allocation fails or if overflow is detected.
 */
void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if ((num == 0) || (size == 0))
		return (malloc(0));
	if (size > 0 && num > __SIZE_MAX__ / size)
		return (NULL);
	ptr = malloc(num * size);
	if ((ptr == NULL) || (ft_bzero(ptr, (num * size)) != ptr))
		return (NULL);
	else
		return (ptr);
}

/* FT_CONVERT_DIGITAL
 * @def Converts a numeric value (0-15) to its hexadecimal character
 *		representation.
 *
 * @param
 *      {unsigned char} c - numeric value to convert (0-15).
 *
 * @returns {char}
 *      OK - Character '0'-'9' for values 0-9, or 'a'-'f' for values 10-15.
 */
char	ft_conver_digital(unsigned char c)
{
	if (c <= 9)
		return (c + '0');
	else
		return (c -10 + 'a');
}

/* FT_STRTOUP
 * @def Converts a string to uppercase in-place and returns the modified string.
 *
 * @param
 *      {char**} text - double pointer to the string to convert.
 *
 * @returns {char*}
 *      OK - Pointer to the uppercase-converted string.
 *      KO - NULL if input is NULL, string is NULL, or memory allocation fails.
 */
char	*ft_strtoup(char **text)
{
	unsigned char			aux;
	unsigned int	i;
	unsigned int	len_text;

	if ((text == NULL) || (*text == NULL))
		return (NULL);
	len_text = ft_strlen((*text));
	aux = ft_calloc((len_text + 1), sizeof(char));
	if (aux == NULL)
		return (NULL);
	i = 0;
	while (i < len_text)
	{
		if ((aux[i] >= 'a') && (aux[i] <= 'z'))
			aux[i] = aux [i] - ('a' - 'A');
		i++;
	}
	aux[i] = '\0';
	free(*text);
	*text = &aux;
	return (*text);
}
