/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:32:23 by rjuarez-          #+#    #+#             */
/*   Updated: 2025/12/11 15:02:16 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conver_unbr_base(long int nbr, int base, int pos);
char	*ft_conver_c(char chr);
char	*ft_conver_s(char *str);
char	*ft_conver_p(void *ptr);
char	*ft_conver_i(long long int nbr);

/* FT_CONVER_UNBR_BASE
 * @def Recursively converts an unsigned long integer to string representation
 * 		in given base.
 *
 * @param
 *      {long int} nbr - number to convert (treated as unsigned).
 *      {int} base - numerical base for conversion (2-16).
 *      {int} pos - current position index (start with 0).
 *
 * @returns {char*}
 *      OK - Dynamically allocated string containing converted number.
 *      KO - NULL if base invalid (<=1) or memory allocation fails.
 *
 * @dev
 *      Recursive algorithm that builds string from most to least significant
 * 			digit.
 *      Uses ft_conver_digital for digit-to-character conversion.
 *      Base must be between 2 and 16 (inclusive) for proper conversion.
 *      Note: Parameter type says 'long int' but function treats it as unsigned.
 */
char	*ft_conver_unbr_base(long int nbr, int base, int pos)
{
	long int	coc;
	char		*aux;
	int			rest;

	if (base <= 1)
		return (NULL);
	if (nbr >= base)
	{
		coc = nbr / base;
		rest = nbr % base;
		aux = ft_conver_unbr_base(coc, base, pos + 1);
	}
	else
	{
		aux = ft_calloc(pos + 2, sizeof(char));
		if (aux == NULL)
			return (NULL);
		aux[pos + 1] = '\0';
		rest = nbr;
	}
	if (aux == NULL)
		return (NULL);
	aux[pos] = ft_conver_digital(rest);
	return (aux);
}

/* FT_CONVER_C
 * @def Converts a single character to dynamically allocated string.
 *
 * @param
 *      {char} chr - character to convert.
 *
 * @returns {char*}
 *      OK - 2-byte string containing character and null terminator.
 *      KO - NULL if memory allocation fails.
 *
 * @dev
 *      Simple wrapper that allocates memory and stores single character.
 *      Useful for consistent string handling in printf pipeline.
 */
char	*ft_conver_c(char chr)
{
	char	*text;

	text = ft_calloc(2, sizeof(char));
	if (text == NULL)
		return (NULL);
	text[0] = chr;
	text[1] = '\0';
	return (text);
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
 *
 * @dev
 *      Standard string duplication function.
 *      Returns NULL for NULL input (printf convention for "(null)" not
 * 			implemented).
 *      Note: For printf, typically should return "(null)" for NULL input.
 */
char	*ft_conver_s(char *str)
{
	char	*text;
	int		i;
	int		len_text;

	if (str == NULL)
		return (NULL);
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
 *
 * @dev
 *      Uses ft_conver_unbr_base with base 16 and starting position 2.
 *      Manually inserts "0x" prefix after conversion.
 *      Note: Starts recursion at position 2 to reserve space for prefix.
 */
char	*ft_conver_p(void *ptr)
{
	char	*text_ptr;

	text_ptr = ft_conver_unbr_base((long int) ptr, 16, 2);
	if (text_ptr == NULL)
		return (NULL);
	text_ptr[0]= '0';
	text_ptr[1]= 'x';
	return (text_ptr);
}

/* FT_CONVER_I
 * @def Converts a signed long long integer to decimal string representation.
 *
 * @param
 *      {long long int} nbr - signed integer to convert.
 *
 * @returns {char*}
 *      OK - String representation of number (with '-' for negatives).
 *      KO - NULL if conversion fails.
 *
 * @dev
 *      Handles negative numbers by converting absolute value and prepending '-'.
 *      Uses ft_conver_unbr_base with base 10.
 *      Starts recursion at position 1 for negatives (reserving space for '-'),
 *      position 0 for positives.
 *
 * @warning
 *      - Uses long long int parameter but ft_conver_unbr_base expects long int.
 *      - Potential overflow with LONG_MIN: -(-LONG_MIN) may overflow.
 *      - Negative zero case not handled (shouldn't occur in practice).
 */
char	*ft_conver_i(long long int nbr)
{
	char			*text_nbr;
	long long int	n;

	n = nbr;
	if (n < 0)
		text_nbr = ft_conver_unbr_base(-n, 10, 1);
	else
		text_nbr = ft_conver_unbr_base(n, 10, 0);
	if (text_nbr == NULL)
		return (NULL);
	if (nbr < 0)
		text_nbr[0] = '-';
	return (text_nbr);
}

