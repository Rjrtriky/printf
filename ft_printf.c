/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 20:54:40 by rjuarez-          #+#    #+#             */
/*   Updated: 2025/12/10 18:32:02 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
- Iniciar argumentos con va_start
- narg = va_
- Inicializar i = 0

Iterar mientras str[i] ≠ '\0':
	- Si str[i] ≠ '%':
		- Imprimir str[i]
	- Si str[i] == '%':
		- i++
		- texto = ft_tipo(str[i], argumento siguiente)
		- Imprimir texto
	- i++

- Finalizar con va_end


-iniciar argmentos con va_stat

-guardar en str el argumento 0 
-inicializar i a 0 
Iteracion: Condicion de entrada str[i] != '\0' 
	-Si (str[i] != '%') 
		-imprimir str[i]
	si no 
		-i++ 
		-texto= ft_tipo(str[i], argumento siguiente) 
		-imprimir texto 
	-i++
*/

int		printf(const char *format, ...);
void	ft_putchr_fd(char c, int fd);
char	*type_check(char chr, va_list param);

/*
%c para imprimir un solo carácter.
%s para imprimir una cadena de caracteres (como se define por defecto en C).
%p el puntero void * dado como argumento se imprime en formato hexadecimal.
%d para imprimir un número decimal (base 10).
%i para imprimir un entero en base 10.
%u para imprimir un número decimal (base 10) sin signo.
%x para imprimir un número hexadecimal (base 16) en minúsculas.
%X para imprimir un número hexadecimal (base 16) en mayúsculas.
%% para imprimir el símbolo del porcentaje.
*/
int	type_check(char *chr, va_list param)
{
	char	*text_param;
	int		len_text_p;

	if (*chr == 'c')
		text_param = ft_conver_c(va_arg(param, int));
	else if (*chr == 's')
		text_param = ft_conver_s(va_arg(param, char *));
	else if (*chr == 'p')
		text_param = ft_conver_p(va_arg(param, void *));
	else if ((*chr == 'i') || (*chr == 'u'))
		text_param = ft_conver_i(va_arg(param, long int));
	else if (*chr == 'x')
		text_param = ft_conver_unbr_base((va_arg(param, unsigned long int)),
				16, 0);
	else if (*chr == 'X')
		text_param = ft_strupper(ft_conver_unbr_base((va_arg(param
							unsigned long int)), 16, 0));
	else if (*chr == '%')
		text_param = ft_conver_c('%');
	if (text_param != NULL)
	{
		ft_putshr_fd(text_param, 1);
		len_text_p = ft_strlen(text_param);
		free(text_param);
		return (len_text_p);
	}
	return (0);
}

int	printf(const char *format, ...)
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
