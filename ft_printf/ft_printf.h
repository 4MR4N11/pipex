/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:20:23 by kel-amra          #+#    #+#             */
/*   Updated: 2022/02/17 15:10:09 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include	<stdlib.h>
# include	<unistd.h>
# include	<stdarg.h>

size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_printf(const char *d, ...);
void	ft_putnbr_unsigned(unsigned int n);
int		ft_putupperx(unsigned int nb);
int		ft_putx(unsigned long nb);
int		ft_byte_len(unsigned int n);
char	*ft_strdup(const char *s1);
#	endif
