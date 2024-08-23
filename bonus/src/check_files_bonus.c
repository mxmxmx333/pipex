/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:19:39 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/16 12:02:44 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int input_file(t_pipex *pipex, char **av)
{
	int	i;

	i = 2;
	pipex->inf = ft_strdup(av[1]);
	if (!pipex->inf)
		return (ft_error(pipex, ERR_MALLOC, NULL, 1), 0);
	if (ft_strcmp(pipex->inf, "here_doc") == 0)
	{
		pipex->limiter = ft_strdup(av[2]);
		if (!pipex->limiter)
			return (ft_error(pipex, ERR_MALLOC, NULL, 1), 1);
		i++;
	}
	return (i);
}

int	b_input_params(t_pipex *pipex, char **av, int ac)
{
	int	i;
	int rev_offs;

	rev_offs = input_file(pipex, av);
	i = rev_offs - 1;
	pipex->cmds = (char ***)ft_calloc(ac - rev_offs + 1, sizeof(char **));
	if (!pipex->cmds)
		return (ft_error(pipex, ERR_MALLOC, NULL, 1), 1);
	while (++i < ac - 1)
	{
		pipex->cmds[i - rev_offs] = ft_split(av[i], ' ');
		if (!pipex->cmds[i - rev_offs])
			return (ft_error(pipex, ERR_MALLOC, NULL, 1), 1);
	}
	pipex->cmds_count = i - rev_offs;
	pipex->cmd_p = ft_calloc(ac - rev_offs, sizeof(char *));
	pipex->outf = ft_strdup(av[ac - 1]);
	if (!pipex->inf || !pipex->outf || !pipex->cmd_p)
		return (ft_error(pipex, ERR_MALLOC, NULL, 1), 1);
	return (1);
}

int	check_files(t_pipex *pipex)
{
	if (ft_strcmp(pipex->inf, "here_doc"))
	{
		if (access(pipex->inf, F_OK) == -1)
			return (perror(pipex->inf), 1);
		if (access(pipex->inf, R_OK) == -1)
			return (ft_error(pipex, ERR_NO_READ, pipex->inf, 0), 0);
	}
	// if (access(pipex->outf, F_OK) == -1)
	// 	return (ft_error(pipex, ERR_NO_FILE, pipex->outf), 0);
	// if (access(pipex->outf, W_OK) == -1)
	// 	return (ft_error(pipex, ERR_NO_WRITE, pipex->outf), 0);
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
			else (free(temp), ft_error(pipex, ERR_NO_EXEC, cmd, 0), 0);
		}
		free(temp);
	}
	// if (!pipex->paths[i])
	// 	return (ft_error(pipex, ERR_CMD_NOT_FOUND, cmd, 0), 0);
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
 