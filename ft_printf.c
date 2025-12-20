/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:54:40 by rjuarez-          #+#    #+#             */
/*   Updated: 2025/12/19 01:27:15 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_check(char chr, va_list p);
int	ft_printf(const char *format, ...);

/* FT_TYPE_CHECK
 * @def Dispatches format specifier to appropriate conversion function and
 *		outputs result.
 *      Routes format specifiers to specific conversion functions:
 *      - 'c': character conversion via ft_conver_c
 *      - 's': string conversion via ft_conver_s
 *      - 'p': pointer conversion via ft_conver_p
 *      - 'i'/'d': integer conversion via ft_conver_i
 *      - 'u': unsigned integer conversion via ft_conver_u
 *      - 'x': lowercase hexadecimal via ft_conver_unbr_base
 *      - 'X': uppercase hexadecimal via ft_strtoup wrapper
 *      - '%': percent literal via ft_conver_c
 *
 * @param
 *      {char*} chr - pointer to format specifier character.
 *      {va_list} p - variable argument list containing values to format.
 *
 * @returns {int}
 *      OK - Number of characters printed (length of converted text).
 *      KO - Returns 0 if conversion returns NULL (e.g., for NULL string input).
 */
int	ft_type_check(char chr, va_list p)
{
	char	*text_param;

	text_param = NULL;
	if (chr == 'c')
		return (ft_conver_c(va_arg(p, int)));
	else if (chr == '%')
		return (ft_conver_c((int) '%'));
	else if (chr == 's')
		text_param = ft_conver_s(va_arg(p, char *));
	else if (chr == 'p')
		text_param = ft_conver_p(va_arg(p, void *));
	else if ((chr == 'i') || (chr == 'd'))
		text_param = ft_conver_nbr_base((long long int)(va_arg(p, int)), 10);
	else if (chr == 'u')
		text_param = ft_conver_nbr_base(va_arg(p, unsigned int), 10);
	else if ((chr == 'x') || (chr == 'X'))
	{
		text_param = ft_conver_nbr_base((va_arg(p, unsigned int)), 16);
		if (chr == 'X')
			text_param = ft_strtoup(&text_param);
	}
	if (text_param == NULL)
		return (0);
	return (ft_puts_fd(&text_param, 1));
}

/* FT_PRINTF
 * @def Custom implementation of printf that processes format string and
 *		variable arguments.
 *
 * @param
 *      {const char*} format - format string containing text and format
 * 			specifiers.
 *      {...} variable arguments - values to be formatted according to
 * 			specifiers.
 *
 * @returns {int}
 *      OK - Total number of characters printed (literal chars + converted args).
 */
int	ft_printf(const char *format, ...)
{
	va_list	list_arg;
	int		i;
	int		count;

	va_start(list_arg, format);
	i = -1;
	count = 0;
	while (format[++i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchr_fd(format[i], 1);
			count++;
		}
		else
		{
			if (format[++i] != '\0')
				count += ft_type_check(format[i], list_arg);
		}
	}
	va_end(list_arg);
	return (count);
}
