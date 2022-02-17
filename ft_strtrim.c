/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:53:20 by kel-amra          #+#    #+#             */
/*   Updated: 2022/02/17 15:18:14 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	len = 0;
	i = 0;
	if (!s1 || !set)
		return (0);
	j = ft_strlen(s1) - 1;
	while (check_set(s1[i], set))
		i++;
	while (check_set(s1[j], set) == 1 && (j > 0))
		j--;
	len = j - i;
	if (len < 0)
		len = 0;
	str = ft_substr(s1, i, len + 1);
	return (str);
}
