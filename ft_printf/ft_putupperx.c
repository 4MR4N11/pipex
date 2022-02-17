/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupperx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:20:10 by kel-amra          #+#    #+#             */
/*   Updated: 2022/02/14 16:46:20 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int nb)
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

static int	fill(unsigned int nb, char *nbr, char *base)
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

int	ft_putupperx(unsigned int nb)
{
	int		i;
	int		res;
	char	*nbr;
	char	*base;
	int		len;

	res = 0;
	base = ft_strdup("0123456789ABCDEF\0");
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
