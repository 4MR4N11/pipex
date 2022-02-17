/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:00:43 by kel-amra          #+#    #+#             */
/*   Updated: 2021/12/11 08:13:10 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static int	fill(unsigned long nb, char *nbr, char *base)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (nb > 0)
	{
		n = nb % 16;
		nb = nb / 16;
		nbr[i++] = base[n];
	}
	return (i);
}

int	ft_putx(unsigned long nb)
{
	int		i;
	int		res;
	char	*nbr;
	char	*base;
	int		len;

	res = 0;
	base = ft_strdup("0123456789abcdef\0");
	if (nb == 0)
		res += write(1, "0", 1);
	len = ft_len(nb);
	nbr = malloc(sizeof(char) * len);
	i = fill(nb, nbr, base);
	while (--i >= 0)
		res += write(1, &nbr[i], 1);
	free(nbr);
	free(base);
	return (res);
}
