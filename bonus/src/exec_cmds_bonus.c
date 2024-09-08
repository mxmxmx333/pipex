/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:44:52 by mbonengl          #+#    #+#             */
/*   Updated: 2024/09/07 12:52:44 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	my_dup2(int pos, int fd[2], int std_fd, t_pipex *pipex)
{
	if (dup2(fd[pos], std_fd) == -1)
	{
		perror("dup2 failed");
		close (fd[0]);
		close (fd[1]);
		exit_p(pipex, 1);
	}
	close (fd[0]);
	close (fd[1]);
}

static void	exec(t_pipex *pipex, int fd_in[2], int fd_out[2], int i)
{
	char	*path;

	if (i == 0)
		open_dup_in(pipex, fd_out);
	else
		my_dup2(0, fd_in, STDIN_FILENO, pipex);
	if (i < pipex->cmds_count - 1)
		my_dup2(1, fd_out, STDOUT_FILENO, pipex);
	else
		open_dup_out(pipex);
	path = get_command_path(pipex, i);
	execve(path, pipex->cmds[i], pipex->env);
	if (path)
		free(path);
	errmsg(pipex, "command not found: ", pipex->cmds[i][0]);
	exit_p(pipex, 127);
}

void	child(t_pipex *pipex, int i, int fd_in[2])
{
	int	pid;
	int	fd_out[2];

	if (i < pipex->cmds_count - 1)
	{
		if (pipe(fd_out) == -1)
			return (perror("pipe failed"),
				close_two(fd_in, i), exit_p(pipex, 1));
	}
	pid = fork();
	if (pid == -1)
		return (perror("fork failed"), close_two(fd_out, 1), exit_p(pipex, 1));
	else if (pid > 0)
	{
		close_two(fd_in, i);
		if (i < pipex->cmds_count - 1)
			child(pipex, i + 1, fd_out);
		else
			pipex->last_pid = pid;
	}
	else
		exec(pipex, fd_in, fd_out, i);
}

static void	ft_pipex(t_pipex *pipex, int *status)
{
	int		last_pid;
	int		fd_in[2];

	child(pipex, 0, fd_in);
	last_pid = pipex->last_pid;
	while (wait(status) != last_pid)
		;
	if (WIFEXITED(*status))
		*status = WEXITSTATUS(*status);
	while (wait(NULL) > 0)
		;
}

int	exec_cmds(t_pipex *pipex)
{
	int	status;

	status = 0;
	gen_here_doc(pipex);
	ft_pipex(pipex, &status);
	return (status);
}
