/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_helpers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:50:48 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/16 11:24:37 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

 void	close_all(t_pipex *pipex)
{
	if (fd_is_valid(pipex->in_out[0]))
		close(pipex->in_out[0]);
	if (fd_is_valid(pipex->in_out[1]))
		close(pipex->in_out[1]);
	if (fd_is_valid(pipex->pipe_fds[0]))
		close(pipex->pipe_fds[0]);
	if (fd_is_valid(pipex->pipe_fds[1]))
		close(pipex->pipe_fds[1]);
}

int	open_out(t_pipex *pipex)
{
	if (pipex->limiter)
		pipex->in_out[1] = open(pipex->outf, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else 
		pipex->in_out[1] = open(pipex->outf, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->in_out[1] == -1)
		return (perror("open outfile failed"), 1);
	return (0);
}
