/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 20:34:26 by rjuarez-          #+#    #+#             */
/*   Updated: 2025/12/08 18:30:43 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  // Donde se declara printf

char	*ft_conver_c(char chr);
char	*ft_conver_s(char *str);
char	*ft_conver_p(void *ptr);
char	*ft_conver_s(int nbr);
char	*ft_conver_u(unsigned int un_nbr);
char	*ft_conver_x(unsigned int h_nbr);

int		printf(const char *format, ...);
void	ft_putchr_fd(char c, int fd);
char	*type_check(char chr, va_list param);
