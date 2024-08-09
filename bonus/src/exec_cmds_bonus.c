/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:44:52 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/08 17:54:59 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_in(t_pipex *pipex, int pipe_fd[2], int in_out[2], char **envp)
{
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		return (perror("in: dup2 failed"), exit_p(pipex, 1));
	close(pipe_fd[1]);
	if (dup2(in_out[0], STDIN_FILENO) == -1)
		return (perror("in: dup2 failed"), exit_p(pipex, 1));
	close(in_out[0]);
	close(in_out[1]);
	execve(pipex->p1, pipex->cmd1, envp);
}

void	exec_out(t_pipex *pipex, int pipe_fd[2], int in_out[2], char **envp)
{
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		return (perror("out: dup2 failed"), exit_p(pipex, 1));
	close (pipe_fd[0]);
	if (dup2(in_out[1], STDOUT_FILENO) == -1)
		return (perror("out: dup2 failed"), exit_p(pipex, 1));
	close (in_out[1]);
	close (in_out[0]);
	execve(pipex->p2, pipex->cmd2, envp);
}

void	close_all(int pipe_fd[2], int in_out[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(in_out[0]);
	close(in_out[1]);
}

void	exec_cmds(t_pipex *pipex, char **envp)
{
	int	pipe_fd[2];
	int	in_out[2];
	int	pid;

	in_out[0] = open(pipex->inf, O_RDONLY);
	if (in_out[0] == -1)
		return (perror("open failed infile"), exit_p(pipex, 1));
	in_out[1] = open(pipex->outf, O_WRONLY);
	if (in_out[1] == -1)
		return (perror("open failed: outfile"), exit_p(pipex, 1));
	if (pipe(pipe_fd) == -1)
		return (perror("pipe failed"), exit_p(pipex, 1));
	pid = fork();
	if (pid == -1)
		return (perror("fork failed"), exit_p(pipex, 1));
	else if (pid == 0)
		exec_in(pipex, pipe_fd, in_out, envp);
	else if (pid > 0)
		exec_out(pipex, pipe_fd, in_out, envp);
	close_all(pipe_fd, in_out);
	exit_p(pipex, 0);
}
