/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-14 23:11:32 by rjuarez-          #+#    #+#             */
/*   Updated: 2025-12-14 23:11:32 by rjuarez-         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_putchr_fd_i(char c, int fd);
int					ft_putstr_fd_i(char *str, int fd);

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
int	ft_putchr_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

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
 */
int	ft_putstr_fd_i(char *str, int fd)
{
	int	len_str;

	if (str == NULL)
		return (0);
	len_str = ft_strlen(str);
	write (fd, str, len_str);
	free(str);
	return (len_str);
}
