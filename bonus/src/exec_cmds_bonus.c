/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:44:52 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/16 12:26:04 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_in(t_pipex *pipex, int pipe_fd[2], int in_out[2])
{
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		return (perror("in: dup2 failed"), exit_p(pipex, 1));
	close(pipe_fd[1]);
	if (dup2(in_out[0], STDIN_FILENO) == -1)
		return (perror("in: dup2 failed"), exit_p(pipex, 1));
	close(in_out[0]);
	close(in_out[1]);
	execve(pipex->cmd_p[0], pipex->cmds[0], pipex->env);
	return (perror("execve failed"), exit_p(pipex, 1));
}

void	exec_middle(t_pipex *pipex, int pipe_fd[2], int in_out[2], int i)
{
	close(pipe_fd[0]);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		return (perror("middle: dup2 failed"), exit_p(pipex, 1));
	close(pipe_fd[1]);
	if (dup2(in_out[1], STDIN_FILENO) == -1)
		return (perror("middle: dup2 failed"), exit_p(pipex, 1));
	close(in_out[1]);
	if (dup2(in_out[0], STDOUT_FILENO) == -1)
		return (perror("middle: dup2 failed"), exit_p(pipex, 1));
	close(in_out[0]);
	execve(pipex->cmd_p[i], pipex->cmds[i], pipex->env);
	return (perror("execve failed"), exit_p(pipex, 1));
}

void	exec_out(t_pipex *pipex, int pipe_fd[2], int in_out[2], int i)
{
	close(pipe_fd[1]);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		return (perror("out: dup2 failed"), exit_p(pipex, 1));
	close (pipe_fd[0]);
	if (dup2(in_out[1], STDOUT_FILENO) == -1)
		return (perror("out: dup2 failed"), exit_p(pipex, 1));
	close (in_out[1]);
	close (in_out[0]);
	execve(pipex->cmd_p[i], pipex->cmds[i], pipex->env);
	return (perror("execve failed"), exit_p(pipex, 1));
}

char	*readline(char *prompt)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	return (line);
}

int here_doc(t_pipex *pipex, int pipe_fd[2])
{
	char	*line;

	close (pipe_fd[0]);
	if (strcmp(pipex->inf, "here_doc") == 0)
	{
		while (1)
		{
			line = readline("here_doc> ");
			if (!line)
				return (perror("readline failed"), exit_p(pipex, 1));
			if (strcmp(line, pipex->limiter) == 0)
			{
				free(line);
				break ;
			}
			ft_putstr_fd(line, pipe_fd[1]);
			free(line);
		}
		close(pipe_fd[1]);
		return (1);
	}
	return (0);
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
		exec_in(pipex, pipe_fd, in_out);
	else if (pid > 0)
		exec_out(pipex, pipe_fd, in_out, envp);
	close_all(pipe_fd, in_out);
	exit_p(pipex, 0);
}
