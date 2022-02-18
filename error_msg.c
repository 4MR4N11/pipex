/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kel-amra <kel-amra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 23:35:58 by kel-amra          #+#    #+#             */
/*   Updated: 2022/02/18 15:26:24 by kel-amra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_msg(t_pipex *tmp)
{
	if (tmp->status[0] == 2)
		ft_printf("Error: Command not found: %s\n", tmp->command1[0]);
	else if (tmp->status[0] == 1)
		ft_printf("Error: Permission denied: %s\n", tmp->command1[0]);
	if (tmp->status[1] == 2)
		ft_printf("Error: command not found: %s\n", tmp->command2[0]);
	else if (tmp->status[1] == 1)
		ft_printf("Error: Permission denied: %s\n", tmp->command2[0]);
}
