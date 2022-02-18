/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:50:40 by kel-amra          #+#    #+#             */
/*   Updated: 2022/02/18 15:27:28 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_command(int infile_fd, int outfile_fd, char **env, t_pipex *tmp)
{
	if (dup2(infile_fd, 0) < 0)
		exit(1);
	if (dup2(tmp->pipe_fd[1], 1) < 0)
		exit(1);
	close_fd(infile_fd, outfile_fd, tmp);
	if (tmp->status[0] == 2)
		exit(1);
	execve(tmp->command_path_1, tmp->command1, env);
	exit(1);
}

int	second_command(int infile_fd, int outfile_fd, char **env, t_pipex *tmp)
{
	if (dup2(outfile_fd, 1) < 0)
		exit (1);
	if (dup2(tmp->pipe_fd[0], 0) < 0)
		exit (1);
	close_fd(infile_fd, outfile_fd, tmp);
	if (tmp->status[1] == 2)
		exit(1);
	execve(tmp->command_path_2, tmp->command2, env);
	exit(1);
}
