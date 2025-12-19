/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:32:23 by rjuarez-          #+#    #+#             */
/*   Updated: 2025/12/19 01:28:40 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conver_null(char chr);
char	*ft_conver_nbr_base(long long int nbr, int base);
int		ft_conver_c(int chr);
char	*ft_conver_s(char *str);
char	*ft_conver_p(void *ptr);

/* FT_CONVER_NULL
 * @def    Converts null values to string representations for printf output.
 *
 * @param  {char} chr - format specifier character that determines which null
 *                      representation to return:
 *                      - 's': returns "(null)" for string null values
 *                      - other: returns "(nil)" for pointer null values
 *
 * @returns {char*}
 *          OK - Dynamically allocated string containing the null representation:
 *               - "(null)" if chr == 's'
 *               - "(nil)" for any other char value
 *          FAIL - NULL if memory allocation fails (calloc returns NULL)
 *
 * @note   The returned string is allocated with calloc and must be freed by
 *         the caller to prevent memory leaks.
 * */
char	*ft_conver_null(char chr)
{
	if (chr == 's')
		return (ft_strdup("(null)"));
	return (ft_strdup("(nil)"));
}

/* FT_CONVER_UNBR_BASE
 * @def Converts an unsigned long integer to string representation in given base.
 *
 * @param
 *      {long int} nbr - number to convert (treated as unsigned).
 *      {int} base - numerical base for conversion (2-35).
 *
 * @returns {char*}
 *      OK - Dynamically allocated string containing converted number.
 *      KO - NULL if base invalid (<=1) or memory allocation fails.
 */
char	*ft_conver_nbr_base(long long int nbr, int base)
{
	char				*aux;
	unsigned long int	unbr;
	int					len;

	if ((base < 2) || (base > 36))
		return (NULL);
	len = ft_intlen_base(nbr, base);
	aux = ft_calloc((len + 1), sizeof(char));
	if (aux == NULL)
		return (NULL);
	if (nbr == 0)
		aux[0] = '0';
	else
	{
		if (nbr < 0)
			aux[0] = '-';
		unbr = ft_abs(nbr);
		while (unbr > 0)
		{
			aux[--len] = ft_conver_digital(unbr % (unsigned long int) base);
			unbr = unbr / (unsigned long int) base;
		}
	}
	return (aux);
}

/* FT_CONVER_C
 * @def Converts a single character to dynamically allocated string.
 *
 * @param
 *      {char} chr - character to convert.
 *
 * @returns {char*}
 *      OK - 1
 */
int	ft_conver_c(int chr)
{
	ft_putchr_fd(chr, 1);
	return (1);
}

/* FT_CONVER_S
 * @def Duplicates a string with dynamic memory allocation.
 *
 * @param
 *      {char*} str - string to duplicate (must be null-terminated).
 *
 * @returns {char*}
 *      OK - Newly allocated copy of input string.
 *      KO - NULL if input is NULL or memory allocation fails.
 */
char	*ft_conver_s(char *str)
{
	char	*text;
	int		i;
	int		len_text;

	if (str == NULL)
		return (ft_conver_null('s'));
	len_text = ft_strlen(str);
	text = ft_calloc(len_text + 1, sizeof(char));
	if (text == NULL)
		return (NULL);
	i = -1;
	while (++i < len_text)
		text[i] = str[i];
	text[len_text] = '\0';
	return (text);
}

/* FT_CONVER_P
 * @def Converts a pointer to hexadecimal string representation with "0x" prefix.
 *
 * @param
 *      {void*} ptr - pointer to convert.
 *
 * @returns {char*}
 *      OK - String in format "0x..." (e.g., "0x7ffeeb5a8e20").
 *      KO - NULL if conversion fails.
 */
char	*ft_conver_p(void *ptr)
{
	char	*text_ptr;
	char	*temp_ptr;
	int		i;

	if (ptr == NULL)
		return (ft_conver_null('p'));
	temp_ptr = ft_conver_nbr_base((long int) ptr, 16);
	if (temp_ptr == NULL)
		return (NULL);
	text_ptr = ft_calloc(ft_strlen(temp_ptr) + 3, sizeof(char));
	if (text_ptr == NULL)
	{
		free(temp_ptr);
		return (NULL);
	}
	text_ptr[0] = '0';
	text_ptr[1] = 'x';
	i = -1;
	while (temp_ptr[++i] != '\0')
		text_ptr[i + 2] = temp_ptr[i];
	text_ptr[i + 2] = '\0';
	free(temp_ptr);
	return (text_ptr);
}
