/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:02:59 by kel-amra          #+#    #+#             */
/*   Updated: 2021/12/06 21:04:40 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr_unsigned((n / 10));
		ft_putnbr_unsigned((n % 10));
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}
