/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-20 20:04:50 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-12-20 20:04:50 by rjuarez-         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				ft_conver_digital(unsigned char c);
int					ft_intlen_base(long long int nbr, int base);
unsigned long int	ft_abs(long long int nbr);
char				*ft_conver_nbr_base(long long int nbr, int base);

/* FT_CONVER_DIGITAL
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

/* FT_INTLEN_BASE
 * @def Computes the length (number of characters) required to represent
 *      a signed long long integer in a given numerical base.
 *
 * @param
 *      {long long int} nbr - number to evaluate.
 *      {int} base - numerical base for conversion (>=2).
 *
 * @returns {int}
 *      OK - Length of string representation, including sign if negative.
 *      KO - Undefined if base < 2.
 *
 * @note
 *      - Returns 1 if nbr == 0.
 *      - Adds one extra character if nbr is negative (for '-').
 */
int	ft_intlen_base(long long int nbr, int base)
{
	int					len;
	unsigned long int	unbr;

	if (nbr == 0)
		return (1);
	len = 0;
	if (nbr < 0)
		len++;
	unbr = ft_abs(nbr);
	while (unbr > 0)
	{
		unbr = unbr / (unsigned long int) base;
		len++;
	}
	return (len);
}
/* FT_ABS
 * @def Returns the absolute value of a signed long long integer,
 *      converted to unsigned long integer.
 *
 * @param
 *      {long long int} nbr - number to convert.
 *
 * @returns {unsigned long int}
 *      OK - Absolute value of nbr, cast to unsigned long int.
 */

unsigned long int	ft_abs(long long int nbr)
{
	if (nbr < 0)
		return ((unsigned long int)(-nbr));
	return ((unsigned long int)(nbr));
}

/* FT_CONVER_NBR_BASE
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
			aux[--len] = ft_conver_digital(unbr % (long long int) base);
			unbr = unbr / (long long int) base;
		}
	}
	return (aux);
}
