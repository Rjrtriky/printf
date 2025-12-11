/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:54:40 by rjuarez-          #+#    #+#             */
/*   Updated: 2025/12/11 15:04:39 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_check(char chr, va_list param);
int		ft_putstr_fd_i(char *str, int fd);
int		ft_printf(const char *format, ...);

/* FT_PUTSTR_FD_I
 * @def Writes a string to the specified file descriptor and returns its length.
 *
 * @param
 *      {char*} str - string to write (must be null-terminated).
 *      {int} fd - file descriptor to write to.
 *
 * @returns {int}
 *      OK - Number of characters written (length of string).
 *      Note: Will crash if str is NULL (dereferenced in ft_strlen).
 *
 * @dev
 *      Uses ft_strlen to calculate string length, then writes entire string
 * 			via write().
 *      Return value matches number of bytes written (should equal string
 * 			length).
 */
int	ft_putstr_fd_i(char *str, int fd)
{
	int	len_str;

	if (str == NULL)
		return (0);
	len_str = ft_strlen(*str);
	write (fd, str, len_str);
	return (len_str);
}

/* FT_TYPE_CHECK
 * @def Dispatches format specifier to appropriate conversion function and
 *		outputs result.
 *
 * @param
 *      {char*} chr - pointer to format specifier character.
 *      {va_list} p - variable argument list containing values to format.
 *
 * @returns {int}
 *      OK - Number of characters printed (length of converted text).
 *      KO - Returns 0 if conversion returns NULL (e.g., for NULL string input).
 *
 * @dev
 *      Routes format specifiers to specific conversion functions:
 *      - 'c': character conversion via ft_conver_c
 *      - 's': string conversion via ft_conver_s
 *      - 'p': pointer conversion via ft_conver_p
 *      - 'i'/'u': integer conversion via ft_conver_i (note: uses long int)
 *      - 'x': lowercase hexadecimal via ft_conver_unbr_base
 *      - 'X': uppercase hexadecimal via ft_strtoup wrapper
 *      - '%': percent literal via ft_conver_c
 *      
 *      Outputs converted text using ft_putstr_fd_i and frees allocated memory.
 *      All conversion functions are expected to return dynamically allocated
 * 			strings.
 *
 * @note
 *      - 'u' format uses ft_conver_i which expects long int, not unsigned int
 *      - 'i' and 'u' share the same conversion function (potentially
 * 			problematic)
 *      - No default case for invalid format specifiers
 *      - ft_strtoup modifies string in-place; ensure it handles NULL returns
 *      - Memory safety: text_param is always freed if not NULL
 */
int	type_check(char *chr, va_list p)
{
	char	*text_param;
	int		len_text_p;

	if (*chr == 'c')
		text_param = ft_conver_c(va_arg(p, int));
	else if (*chr == 's')
		text_param = ft_conver_s(va_arg(p, char *));
	else if (*chr == 'p')
		text_param = ft_conver_p(va_arg(p, void *));
	else if ((*chr == 'i') || (*chr == 'u'))
		text_param = ft_conver_i(va_arg(p, long int));
	else if (*chr == 'x')
		text_param = ft_conver_unbr_base((va_arg(p, unsigned long int)), 16, 0);
	else if (*chr == 'X')
		text_param = ft_strtoup(ft_conver_unbr_base((va_arg(p,
							unsigned long int)), 16, 0));
	else if (*chr == '%')
		text_param = ft_conver_c('%');
	if (text_param != NULL)
	{
		len_text_p = ft_putstr_fd_i(text_param, 1);
		free(text_param);
		return (len_text_p);
	}
	return (0);
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
 *      Note: Current implementation has multiple critical bugs.
 *
 * @dev
 *      Iterates through format string, printing literal characters directly.
 *      When '%' encountered, calls type_check to process format specifier.
 *      Tracks total printed characters via i (literal count) + len_plus 
 * 			(converted args).
 */
int	ft_printf(const char *format, ...)
{
	va_list	list_arg;
	char	*arg1;
	char	*text;
	int		i;
	int		len_plus;

	va_start(list_arg, format);
	arg1 = va_arg(list_arg, format);
	i = 0;
	len_plus = 0;
	while (arg1[i] != '\0')
	{
		if arg1[i] != '%'
			ft_putchr_fd(arg1[i], 1);
		else
		{
			i++;
			len_plus = len_plus + type_check(arg1[i], list_arg);
		}
		i++;
	}
	return (i + len_plus);
}
