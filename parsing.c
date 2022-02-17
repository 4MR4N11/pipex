/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:47:08 by kel-amra          #+#    #+#             */
/*   Updated: 2022/02/17 23:50:04 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	access_checker(char **command_path)
{
	int	fd_checker;

	if (access((*command_path), F_OK) == 0)
	{
		fd_checker = open(*command_path, O_DIRECTORY);
		if (fd_checker < 0 && access(*command_path, X_OK) == 0)
			return (0);
		free(*command_path);
		*command_path = NULL;
		return (1);
	}
	return (2);
}

void	commands_spliter(char *cmd1, char *cmd2, char **env, t_pipex *tmp)
{
	char	*str;
	int		i;

	tmp->command1 = ft_split(cmd1, ' ');
	tmp->command2 = ft_split(cmd2, ' ');
	str = path_grepper(env);
	tmp->path_env = ft_split(str, ':');
	free(str);
	tmp->status[0] = path_spliter(tmp->command1[0], &tmp->command_path_1, tmp);
	tmp->status[1] = path_spliter(tmp->command2[0], &tmp->command_path_2, tmp);
	i = -1;
	while (tmp->path_env && tmp->path_env[++i])
	{
		free(tmp->path_env[i]);
		tmp->path_env[i] = NULL;
	}
	free(tmp->path_env);
	tmp->path_env = NULL;
}
