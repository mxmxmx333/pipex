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

/* void	close_all(int pipe_fd[2], int in_out[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(in_out[0]);
	close(in_out[1]);
}

int	open_files(t_pipex *pipex, int in_out[2])
{
	in_out[0] = open(pipex->inf, O_RDONLY);
	if (in_out[0] == -1)
		return (perror("open infile failed"), 1);
	in_out[1] = open(pipex->outf, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (in_out[1] == -1)
		return (perror("open outfile failed"), 1);
	return (0);
} */ 