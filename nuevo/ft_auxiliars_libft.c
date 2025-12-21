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

size_t	ft_strlen(const char *str);
void	*ft_bzero(void *ptr, size_t len);
void	*ft_calloc(size_t num, size_t size);
void	*ft_recalloc(unsigned char *old_ptr, unsigned long int new_size);
char	*ft_strdup(const char *ori);

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

/*FT_RECALLOC
 * @def	Resize a received pointer variable with the size also received
 *
 * @param
 *		{unsigned char} <nombre del parametro> - que reibe
 *		{number} <nombre del parametro> - que reibe
 *
 * @returns {unsigned char}
 *		OK - string with changed size.
 *		KO - NULL
 * */
void	*ft_recalloc(unsigned char *old_ptr, unsigned long int new_size)
{
	unsigned char	*new_ptr;
	long long int	i;
	size_t			old_size;

	if (new_size == 0)
	{
		free(old_ptr);
		return (NULL);
	}
	new_ptr = (unsigned char *) ft_calloc(new_size, 1);
	if (new_ptr == NULL)
		return (NULL);
	if (old_ptr != NULL)
	{
		old_size = ft_strlen((char *) old_ptr);
		i = -1;
		while ((++i < (int) old_size) && (i < (int) new_size))
			new_ptr[i] = old_ptr[i];
	}
	free(old_ptr);
	old_ptr = new_ptr;
	return (new_ptr);
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
