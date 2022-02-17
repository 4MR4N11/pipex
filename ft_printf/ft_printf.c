/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:36:30 by kel-amra          #+#    #+#             */
/*   Updated: 2021/12/11 08:14:52 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

va_list			g_ptr;
int				g_ret;
int				g_tmp;
int				g_i;
unsigned int	g_num;

static void	process_conversions(const char *format)
{
	if (format[g_i] == 's')
		g_ret = ft_putstr(va_arg(g_ptr, char *));
	if (format[g_i] == 'd' || format[g_i] == 'i')
		g_ret = ft_putnbr(va_arg(g_ptr, int));
	if (format[g_i] == 'c')
		g_ret = ft_putchar(va_arg(g_ptr, int));
	if (format[g_i] == 'u')
	{
		g_num = va_arg(g_ptr, unsigned int);
		ft_putnbr_unsigned(g_num);
		g_ret = ft_byte_len(g_num);
	}
	if (format[g_i] == '%')
		g_ret = ft_putchar(format[g_i]);
	if (format[g_i] == 'x')
		g_ret = ft_putx(va_arg(g_ptr, unsigned int));
	if (format[g_i] == 'X')
		g_ret = ft_putupperx(va_arg(g_ptr, unsigned int));
	if (format[g_i] == 'p')
	{
		write(1, "0x", 2);
		g_ret = ft_putx(va_arg(g_ptr, unsigned long));
		g_ret += 2;
	}
}

int	ft_printf(const char *format, ...)
{
	g_ret = 0;
	g_i = 0;
	va_start(g_ptr, format);
	while (format[g_i] != '\0')
	{
		g_tmp = g_ret;
		if (format[g_i] == '%')
		{
			g_i++;
			process_conversions(format);
			g_ret = g_ret + g_tmp;
		}
		else
		{
			ft_putchar(format[g_i]);
			g_ret++;
		}
		g_i++;
	}
	va_end(g_ptr);
	return (g_ret);
}
