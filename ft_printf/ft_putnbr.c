/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:45:47 by kel-amra          #+#    #+#             */
/*   Updated: 2021/12/11 09:00:48 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len(int n)
{
	int	j;

	j = 0;
	while (n > 0 || n < 0)
	{
		if (n < 0)
			n *= -1;
		n /= 10;
		j++;
	}
	return (j);
}

static int	negative(int *n, int *j, int k)
{
	if ((*n) < 0)
	{
		if (k)
		{
			write(1, "-", 1);
			(*j)++;
		}
		if ((*n) == -2147483648)
		{
			if (k)
				write(1, "2147483648", 10);
			return (11);
		}
		if (k)
			(*n) *= -1;
	}
	return (0);
}

int	ft_putnbr(int n)
{
	int		j;
	char	c;

	j = 0;
	if (n == 0)
		j++;
	j = j + len(n);
	if (negative(&n, &j, 1))
		return (negative(&n, &j, 0));
	if (n >= 10)
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
	return (j);
}
