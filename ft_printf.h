/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 20:34:26 by rjuarez-          #+#    #+#             */
/*   Updated: 2025/12/11 14:51:14 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

// ft_auxiliars_libft.c
size_t				ft_strlen(const char *str);
void				*ft_bzero(void *ptr, size_t len);
void				*ft_calloc(size_t num, size_t size);
char				ft_conver_digital(unsigned char c);
char				*ft_strtoup(char **text);

// ft_conver.c
int					ft_intlen_base(long long int nbr, int base);
char				*ft_conver_nbr_base(long long int nbr, int base);
char				*ft_conver_c(char chr);
char				*ft_conver_s(char *str);
char				*ft_conver_p(void *ptr);

// ft_puts.c
int					ft_putchr_fd(char c, int fd);
int					ft_putstr_fd_i(char *str, int fd);

// ft_printf.c
unsigned long int	ft_abs(long long int nbr);
char				*type_check(char *chr, va_list p);
int					ft_printf(const char *format, ...);

#endif
