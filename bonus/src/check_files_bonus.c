/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:19:39 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/08 17:57:53 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	input_params(t_pipex *pipex, char **av)
{
	pipex->inf = ft_strdup(av[1]);
	pipex->cmd1 = ft_split(av[2], ' ');
	pipex->cmd2 = ft_split(av[3], ' ');
	pipex->outf = ft_strdup(av[4]);
	if (!pipex->inf || !pipex->cmd1 || !pipex->cmd2 || !pipex->outf)
		return (ft_error(pipex, ERR_MALLOC, NULL), 0);
	return (1);
}

int	check_files(t_pipex *pipex)
{
	if (access(pipex->inf, F_OK) == -1)
		return (ft_error(pipex, ERR_NO_FILE, pipex->inf), 0);
	if (access(pipex->inf, R_OK) == -1)
		return (ft_error(pipex, ERR_NO_READ, pipex->inf), 0);
	if (access(pipex->outf, F_OK) == -1)
		return (ft_error(pipex, ERR_NO_FILE, pipex->outf), 0);
	if (access(pipex->outf, W_OK) == -1)
		return (ft_error(pipex, ERR_NO_WRITE, pipex->outf), 0);
	return (1);
}

static int	check_commands_2(t_pipex *pipex)
{
	char	*temp;
	int		i;

	i = -1;
	while (pipex->paths[++i])
	{
		temp = ft_strjoin_three(pipex->paths[i], "/", pipex->cmd2[0]);
		if (access(temp, F_OK) == 0)
		{
			if (access(temp, X_OK) == 0)
			{
				pipex->p2 = temp;
				break ;
			}
			else (free(temp), ft_error(pipex, ERR_NO_EXEC, pipex->cmd2[0]), 0);
		}
		free(temp);
	}
	if (!pipex->paths[i])
		return (ft_error(pipex, ERR_CMD_NOT_FOUND, pipex->cmd2[0]), 0);
	return (1);
}

int	check_commands(t_pipex *pipex)
{
	char	*temp;
	int		i;

	i = -1;
	while (pipex->paths[++i])
	{
		temp = ft_strjoin_three(pipex->paths[i], "/", pipex->cmd1[0]);
		if (access(temp, F_OK) == 0)
		{
			if (access(temp, X_OK) == 0)
			{
				pipex->p1 = temp;
				break ;
			}
			else (free(temp), ft_error(pipex, ERR_NO_EXEC, pipex->cmd1[0]), 0);
		}
		free(temp);
	}
	if (!pipex->paths[i])
		return (ft_error(pipex, ERR_CMD_NOT_FOUND, pipex->cmd1[0]), 0);
	return (check_commands_2(pipex));
}
