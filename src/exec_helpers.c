/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helpers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:50:48 by mbonengl          #+#    #+#             */
/*   Updated: 2024/09/06 17:02:42 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_two(int fd[2], int i)
{
	if (i > 0)
	{
		close(fd[0]);
		close(fd[1]);
	}
}

void	open_dup_out(t_pipex *pipex)
{
	if (pipex->limiter)
		pipex->in_out[1] = open \
			(pipex->outf, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->in_out[1] = open \
			(pipex->outf, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->in_out[1] == -1)
		return (perror(pipex->outf), exit_p(pipex, 1));
	if (dup2(pipex->in_out[1], STDOUT_FILENO) == -1)
		return (perror("dup2 failed"), exit_p(pipex, 1));
	close(pipex->in_out[1]);
}

void	open_dup_in(t_pipex *pipex, int fd[2])
{
	pipex->in_out[0] = open(pipex->inf, O_RDONLY);
	if (pipex->in_out[0] == -1)
		return (perror(pipex->inf), close_two(fd, 1), exit_p(pipex, 1));
	if (dup2(pipex->in_out[0], STDIN_FILENO) == -1)
		return (perror("dup2 failed"), close_two(fd, 1), exit_p(pipex, 1));
	close(pipex->in_out[0]);
}

char	*get_command_path(t_pipex *pipex, int i)
{
	int		j;
	char	*path;

	j = -1;
	if (pipex->cmds[i][0] == NULL)
		return (NULL);
	if (access(pipex->cmds[i][0], F_OK))
	{
		while (pipex->paths && pipex->paths[++j])
		{
			path = ft_strjoin_three(pipex->paths[j], "/", pipex->cmds[i][0]);
			if (!path)
				return (ft_error(pipex, ERR_MALLOC, NULL, 1), NULL);
			if (access(path, F_OK) == 0)
				return (path);
			free(path);
		}
	}
	else if (access(pipex->cmds[i][0], X_OK))
		return (perror(pipex->cmds[i][0]), exit_p(pipex, 126), NULL);
	return (ft_strdup(pipex->cmds[i][0]));
}
