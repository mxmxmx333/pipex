/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:29:19 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/15 17:43:28 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_pipex_struct(t_pipex *pipex)
{
	int	i;
	char ***cmds = pipex->cmds;

	i = 0;
	ft_putstr_fd("inf: ", 1);
	ft_putendl_fd(pipex->inf, 1);
	ft_putstr_fd("outf: ", 1);
	ft_putendl_fd(pipex->outf, 1);
	ft_putstr_fd("cmd1: ", 1);
	ft_putstr_fd("p1: ", 1);
	if (pipex->cmd_p)
	{
		while (pipex->cmd_p[i])
		{
			ft_putendl_fd(pipex->cmd_p[i], 1);
			i++;
		}
	}
	
	ft_putstr_fd("paths: \n", 1);
	i = 0;
	while (pipex->paths[i])
	{
		ft_putendl_fd(pipex->paths[i], 1);
		i++;
	}
	i = 0;
	
	int j = 0;
	ft_putstr_fd("cmds: \n", 1);
	while (cmds[i])
	{
		j = 0;
		while (cmds[i][j])
		{
			ft_putendl_fd(cmds[i][j], 1);
			j++;
		}
		i++;
	}
}