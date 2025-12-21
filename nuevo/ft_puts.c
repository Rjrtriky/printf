/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 23:11:32 by rjuarez-          #+#    #+#             */
/*   Updated: 2025/12/19 01:27:58 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchr_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
int		ft_puts_fd(char **text, int fd);

/* FT_PUTCHAR_FD
 * @def Writes a single character to the specified file descriptor.
 *
 * @param
 *      {char} c - character to write.
 *      {int} fd - file descriptor to write to.
 *
 * @returns {void}
 *      No return value.
 */
void	ft_putchr_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* FT_PUTSTR_FD
 * @def Writes a string to the specified file descriptor and returns its length.
 *
 * @param
 *      {char*} str - string to write (must be null-terminated).
 *      {int} fd - file descriptor to write to.
 *
 * @returns {int}
 *      OK - Number of characters written (length of string).
 *      Note: Will crash if str is NULL (dereferenced in ft_strlen).
 */
void	ft_putstr_fd(char *str, int fd)
{
	int	len_str;

	if (str != NULL)
	{
		len_str = ft_strlen(str);
		write (fd, str, len_str);
	}
}

/* FT_PRINTER
 * @def Outputs a dynamically allocated string to standard output,
 *      then frees the string.
 *
 * @param
 *      {char**} text - pointer to dynamically allocated string to print.
 *
 * @returns {int}
 *      OK - Length of printed string.
 *      KO - 0 if text is NULL.
 */
int	ft_puts_fd(char **text, int fd)
{
	int	len_text;

	if ((text == NULL) || (*text == NULL))
		return (0);
	len_text = ft_strlen(*text);
	ft_putstr_fd(*text, fd);
	free(*text);
	*text = NULL;
	return (len_text);
}
