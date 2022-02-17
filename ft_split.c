/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:02:06 by kel-amra          #+#    #+#             */
/*   Updated: 2022/02/17 15:17:51 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check(char **strs, int row)
{
	if (strs[row] == NULL)
	{
		while (row)
			free(strs[row--]);
		return (1);
	}
	return (0);
}

static int	countrow(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!*s)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	**countcolumn(char const *s, char c, char **strs, int words)
{
	int	i;
	int	row;
	int	count;
	int	start;

	start = 0;
	row = 0;
	i = 0;
	count = 0;
	while (row < words)
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[count + i] != c && s[count + i] != '\0')
			count++;
		i += count;
		strs[row] = ft_substr(s, start, count);
		if (check(strs, row++) == 1)
			return (NULL);
		count = 0;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;

	if (!s)
		return (0);
	words = countrow(s, c);
	strs = (char **)malloc(sizeof(char *) * (words + 1));
	if (!strs)
	{
		free(strs);
		return (0);
	}
	strs[words] = NULL;
	strs = countcolumn(s, c, strs, words);
	return (strs);
}
