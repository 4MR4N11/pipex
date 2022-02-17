/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:01:48 by kel-amra          #+#    #+#             */
/*   Updated: 2022/02/17 15:18:10 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	l = 0;
	j = 0;
	i = 0;
	if (haystack[i] == '\0' && needle[i] == '\0')
		return ("");
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		l = i;
		while (haystack[l] == needle[j] && l < len)
		{
			if ((haystack[l] == needle[j]) && (needle[j + 1] == '\0' ))
				return ((char *)haystack + i);
			l++;
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
