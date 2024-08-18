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

void	child(t_pipex *pipex, int i)
{
	int	pid;
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (perror("pipe failed"), exit_p(pipex, 1));
	pid = fork();
	if (pid == -1)
		return (perror("fork failed"), exit_p(pipex, 1));
	else if (pid > 0)
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			return (perror("dup2 failed"), exit_p(pipex, 1));
		close(pipe_fd[0]);
	}
	else
	{
		close (pipe_fd[0]);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			return (perror("dup2 failed"), exit_p(pipex, 1));
		close(pipe_fd[1]);
		execve(pipex->cmd_p[i], pipex->cmds[i], pipex->env);
		printf("execve failed i: %d\n", i);
		return (perror("execve failed"), exit_p(pipex, 1));
	}
}

static void	ft_pipex(t_pipex *pipex)
{
	int		i;

	i = -1;
	while (++i < pipex->cmds_count - 1)
		child(pipex, i);
	while (wait(NULL) > 0)
		;
}

void	exec_cmds(t_pipex *pipex)
{
	//here_doc(pipex);
	pipex->in_out[0] = open(pipex->inf, O_RDONLY);
	if (pipex->in_out[0] == -1)
		return (perror("open failed"), exit_p(pipex, 1));
	dup2(pipex->in_out[0], STDIN_FILENO);
	close(pipex->in_out[0]);
	ft_pipex(pipex);
	// char buf[10];
	// read(STDIN_FILENO, &buf, 10);
	open_out(pipex);
	if (dup2(pipex->in_out[1], STDOUT_FILENO) == -1)
		return (perror("dup2 fail"), exit_p(pipex, 1));
	close(pipex->in_out[1]);
	execve(pipex->cmd_p[pipex->cmds_count - 1], pipex->cmds[pipex->cmds_count - 1], pipex->env);
	exit_p(pipex, 0);
}

/* char	*readline(char *prompt)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	return (line);
} */
/* 
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
} */