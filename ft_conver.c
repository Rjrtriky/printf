/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjuarez- <rjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:32:23 by rjuarez-          #+#    #+#             */
/*   Updated: 2025/12/10 18:30:50 by rjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_conver_c(char chr);
char	*ft_conver_s(char *str);
char	*ft_conver_p(void *ptr);
char	*ft_conver_i(int nbr);
char	ft_conver_digital(unsigned char c);
char	*ft_conver_unbr_base(long int nbr, int base, int pos);

char	ft_conver_digital(unsigned char c)
{
	if (c <= 9)
		return (c + '0');
	else
		return (c -10 + 'a');

}

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

char	*ft_conver_p(void *ptr)
{

}

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

