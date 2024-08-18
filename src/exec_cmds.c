/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:44:52 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/16 12:18:38 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_files(t_pipex *pipex, int in_out[2])
{
	in_out[0] = open(pipex->inf, O_RDONLY);
	if (in_out[0] == -1)
		return (perror("open infile failed"), 1); 
	in_out[1] = open(pipex->outf, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (in_out[1] == -1)
		return (perror("open outfile failed"), 1);
	return (0);
}

void	close_all(int pipe_fd[2], int in_out[2])
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(in_out[0]);
	close(in_out[1]);
}

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

void	exec_cmds(t_pipex *pipex, char **envp)
{
	int	pipe_fd[2];
	int	in_out[2];
	int	pid;

	open_files(pipex, in_out);
	if (pipe(pipe_fd) == -1)
		return (perror("pipe failed"), exit_p(pipex, 1));
	pid = fork();
	if (pid == -1)
		return (perror("fork failed"), exit_p(pipex, 1));
	else if (pid == 0)
		exec_in(pipex, pipe_fd, in_out, envp);
	else
		exec_out(pipex, pipe_fd, in_out, envp);
	wait(NULL);
	close_all(pipe_fd, in_out);
	exit_p(pipex, 0);
}
