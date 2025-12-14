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

// ft_auxiliars.c
size_t	ft_strlen(const char *str);
void	*ft_bzero(void *ptr, size_t len);
void	*ft_calloc(size_t num, size_t size);
char	ft_conver_digital(unsigned char c);
char	*ft_strtoup(char **text);

// ft_conver.c
char	*ft_conver_unbr_base(long int nbr, int base, int pos);
char	*ft_conver_c(char chr);
char	*ft_conver_s(char *str);
char	*ft_conver_p(void *ptr);
char	*ft_conver_i(long long int nbr);

// ft_printf.c
int		ft_printf(const char *format, ...);
int		ft_putstr_fd_i(char *str, int fd);

#endif