/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:47:16 by kel-amra          #+#    #+#             */
/*   Updated: 2022/02/17 23:57:00 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PIPEX_H
# define PIPEX_H

# include	<unistd.h>
# include	<stdio.h>
# include	<errno.h>
# include	<stdlib.h>
# include	<string.h>
# include	<fcntl.h>
# include	"ft_printf/ft_printf.h"
# include	<sys/wait.h>

typedef struct s_pipex
{
	int		pipe_fd[2];
	int		pids[2];
	char	**path_env;
	char	*command_path_1;
	char	*command_path_2;
	char	**command1;
	char	**command2;
	int		status[2];
	int		exitstatus;
	int		oldint;
	int		oldout;
}	t_pipex;
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
void	free_data(t_pipex *tmp);
char	*path_grepper(char **env);
void	error_msg(t_pipex *tmp);
void	close_fd(int infile_fd, int outfile_fd, t_pipex *tmp);
int		access_checker(char **command_path);
int		path_spliter(char *command, char **command_path, t_pipex *tmp);
int		first_command(int infile_fd, int outfile_fd, char **env, t_pipex *tmp);
int		second_command(int infile_fd, int outfile_fd, char **env, t_pipex *tmp);
void	commands_spliter(char *cmd1, char *cmd2, char **env, t_pipex *tmp);

#	endif