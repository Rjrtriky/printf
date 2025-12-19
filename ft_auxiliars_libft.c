/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxiliars_libft.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:25:21 by rjuarez-          #+#    #+#             */
/*   Updated: 2025/12/19 01:29:02 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	unsigned int	i;
	unsigned int	len_text;

	if ((text == NULL) || (*text == NULL))
		return (NULL);
	len_text = ft_strlen((*text));
	i = 0;
	while (i < len_text)
	{
		if (((*text)[i] >= 'a') && ((*text)[i] <= 'z'))
			(*text)[i] = (*text)[i] - ('a' - 'A');
		i++;
	}
	return (*text);
}

/* FT_STRDUP
 * @def    Creates a duplicate of a null-terminated string.
 *
 * @param  {const char*} ori - Source string to be duplicated.
 *
 * @returns {char*}
 *          OK - Pointer to newly allocated memory containing an exact copy
 *               of the source string, including the null terminator.
 *          FAIL - NULL if memory allocation fails (malloc returns NULL).
 */
char	*ft_strdup(const char *ori)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = ft_strlen((char *)ori);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = ori[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}
