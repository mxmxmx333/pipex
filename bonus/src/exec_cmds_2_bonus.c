
#include "pipex_bonus.h"

void	generate_pipes(t_pipex *pipex)
{
	int	i;

	i = -1;
	pipex->pipe_fds = malloc(sizeof(int *) * pipex->cmds_count);
	while (++i < pipex->cmds_count)
	{
		if (pipe(pipex->pipe_fds[i]) == -1)
			return (perror("pipe failed"), exit_p(pipex, 1));
	}
}

void	exec_commands_all(t_pipex *pipex)
{
	generate_pipes(pipex);
	open(pipex->inf, O_RDONLY);
	if (dup2(pipex->in_out[0], pipex->pipe_fds[0][1]) == -1)
		return (perror("dup2 failed"), exit_p(pipex, 1));
	close(pipex->in_out[0]);
	int	i = -1;
	int	pid;
	while (++i < pipex->cmds_count - 1)
	{
		pid = fork();
		if (pid == -1)
			return (perror("fork failed"), exit_p(pipex, 1));
		else if (pid > 0)
		{
			close(pipex->pipe_fds[i][1]);
			if (dup2(pipex->pipe_fds[i][0], STDIN_FILENO) == -1)
				return (perror("dup2 failed"), exit_p(pipex, 1));
			close(pipex->pipe_fds[i][0]);
		}
		else
		{
			close(pipex->pipe_fds[i][0]);
			if (dup2(pipex->pipe_fds[i + 1][1], STDOUT_FILENO) == -1)
				return (perror("dup2 failed"), exit_p(pipex, 1));
			close(pipex->pipe_fds[i][1]);
			execve(pipex->cmds[i][0], pipex->cmds[i], pipex->env);
			return (perror("execve failed"), exit_p(pipex, 1));
		}
	}
}