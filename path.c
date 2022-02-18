/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:26:49 by kel-amra          #+#    #+#             */
/*   Updated: 2022/02/18 15:27:54 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fullpath_case(t_pipex *tmp, char *command, char **command_path)
{
	int	i;
	int	ret;

	i = -1;
	ret = 0;
	while (tmp->path_env[++i])
	{
		if (ft_strnstr(command, tmp->path_env[i], ft_strlen(tmp->path_env[i])))
		{
			*command_path = ft_strdup(command);
			ret = access_checker(command_path);
			if (!ret || ret == 1)
				return (ret);
		}
	}
	return (2);
}

char	*path_grepper(char **env)
{
	char	*str;
	int		i;

	i = 0;
	while (env[i])
	{
		str = env[i++];
		if (ft_strnstr(str, "PATH=", 5))
		{
			str = ft_strtrim(str, "PATH=");
			return (str);
		}
	}
	return (NULL);
}

int	path_spliter(char *command, char **command_path, t_pipex *tmp)
{
	int		i;
	int		ret;
	char	*str;

	str = NULL;
	i = -1;
	while (tmp->path_env[++i])
	{
		str = ft_strjoin(tmp->path_env[i], "/");
		*command_path = ft_strjoin(str, command);
		free(str);
		ret = access_checker(command_path);
		if (!ret || ret == 1)
			return (ret);
		free(*command_path);
		*command_path = NULL;
	}
	i = -1;
	return (fullpath_case(tmp, command, command_path));
}
