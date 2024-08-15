/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:19:39 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/15 19:41:33 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	b_input_params(t_pipex *pipex, char **av, int ac)
{
	int	i;

	i = 1;
	
	pipex->inf = ft_strdup(av[1]);
	pipex->cmds = (char ***)ft_calloc(ac - 2, sizeof(char **));
	if (!pipex->inf || !pipex->cmds)
		return (ft_error(pipex, ERR_MALLOC, NULL), 0);
	while (++i <= ac - 2)
	{
		pipex->cmds[i - 2] = ft_split(av[i], ' ');
		if (!pipex->cmds[i - 2])
			return (ft_error(pipex, ERR_MALLOC, NULL), 0);
	}
	pipex->cmd_p = ft_calloc(ac - 2, sizeof(char *));
	pipex->outf = ft_strdup(av[ac - 1]);
	if (!pipex->inf || !pipex->outf || !pipex->cmd_p)
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

static int	check_command_path(t_pipex *pipex, char *cmd, int j)

{
	char	*temp;
	int		i;

	i = -1;
	while (pipex->paths[++i])
	{
		temp = ft_strjoin_three(pipex->paths[i], "/", cmd);
		if (access(temp, F_OK) == 0)
		{
			if (access(temp, X_OK) == 0)
			{
				pipex->cmd_p[j] = temp;
				break ;
			}
			else (free(temp), ft_error(pipex, ERR_NO_EXEC, cmd), 0);
		}
		free(temp);
	}
	if (!pipex->paths[i])
		return (ft_error(pipex, ERR_CMD_NOT_FOUND, cmd), 0);
	return (1);
}

int	check_commands(t_pipex *pipex)
{
	int i;

	i = -1;
	while (pipex->cmds[++i])
	{
		if (!check_command_path(pipex, pipex->cmds[i][0], i))
			return (0);
	}
	return (1);
}
 