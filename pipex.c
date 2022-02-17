/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:11:31 by kel-amra          #+#    #+#             */
/*   Updated: 2022/02/17 23:56:43 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int infile_fd, int outfile_fd, t_pipex *tmp)
{
	close(tmp->pipe_fd[1]);
	close(tmp->pipe_fd[0]);
	close(outfile_fd);
	close(infile_fd);
}

void	free_data(t_pipex *tmp)
{
	int		i;

	i = -1;
	while (tmp->command1 && tmp->command1[++i])
	{
		free(tmp->command1[i]);
		tmp->command1[i] = NULL;
	}
	free(tmp->command1);
	i = -1;
	while (tmp->command2 && tmp->command2[++i])
	{
		free(tmp->command2[i]);
		tmp->command2[i] = NULL;
	}
	free(tmp->command2);
	if (tmp->command_path_1)
		free(tmp->command_path_1);
	if (tmp->command_path_2)
		free(tmp->command_path_2);
}

void	forking(t_pipex *tmp, int infile_fd, int outfile_fd, char **env)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		tmp->pids[i] = fork();
		if (!tmp->pids[i] && !i)
			first_command(infile_fd, outfile_fd, env, tmp);
		else if (!tmp->pids[i] && i)
			second_command(infile_fd, outfile_fd, env, tmp);
	}
}

int	pipex(int infile_fd, int outfile_fd, t_pipex *tmp, char **env)
{
	int	i;

	i = 0;
	error_msg(tmp);
	pipe (tmp->pipe_fd);
	tmp->oldint = dup(0);
	tmp->oldout = dup(1);
	forking(tmp, infile_fd, outfile_fd, env);
	close_fd(infile_fd, outfile_fd, tmp);
	dup2(tmp->oldint, 0);
	dup2(tmp->oldout, 1);
	i = -1;
	while (++i < 2)
	{
		waitpid(tmp->pids[i], &tmp->exitstatus, 0);
		tmp->exitstatus = WEXITSTATUS(tmp->exitstatus);
	}
	free_data(tmp);
	return (tmp->exitstatus);
}

int	main(int ac, char **av, char **env)
{
	int		infile_fd;
	int		outfile_fd;
	t_pipex	tmp;

	if (!env[0])
		return (ft_printf("Error: Environment is null"), 1);
	tmp = (t_pipex){0};
	if (ac != 5)
	{
		ft_printf("Error: to few arguments");
		return (1);
	}
	infile_fd = open(av[1], O_RDONLY);
	if (infile_fd < 0)
		ft_printf("Error: %s: %s\n", strerror(errno), av[1]);
	outfile_fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile_fd < 0)
		ft_printf("Error: %s: %s\n", strerror(errno), av[4]);
	if ((infile_fd < 0) && (outfile_fd < 0))
		return (1);
	commands_spliter(av[2], av[3], env, &tmp);
	return (pipex(infile_fd, outfile_fd, &tmp, env));
}
