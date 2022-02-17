/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:10:59 by kel-amra          #+#    #+#             */
/*   Updated: 2022/02/17 23:23:55 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*conct;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	conct = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!conct)
		return (NULL);
	while (s1[i] != '\0' && s1)
	{
		conct[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && s2)
	{
		conct[i] = s2[j];
		j++;
		i++;
	}
	conct[i] = '\0';
	return (conct);
}
