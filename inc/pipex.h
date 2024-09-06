/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:02:26 by mbonengl          #+#    #+#             */
/*   Updated: 2024/09/06 17:02:17 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "errors.h" // error messages
# include "errno.h" // ernno
# include "libft.h" // libft functions
# include <sys/wait.h> // waitpid
# include <fcntl.h> // open, O_RDONLY, O_WRONLY, O_CREAT, O_TRUNC
# include <unistd.h> // write, close, fork, execve, pipe, dup2, access, open

typedef struct s_pipex
{
	char	***cmds;
	char	*inf;
	char	*outf;
	char	*limiter;
	char	**paths;
	char	**env;
	char	*exec_path;
	int		cmds_count;
	int		in_out[2];
	int		last_pid;
}	t_pipex;

/* ------------------------- error handling --------------------------*/
void	ft_error(t_pipex *pipex, char *error, char *place, int status);
void	errmsg(t_pipex *pipex, char *error, char *place);
char	**emptystr(void);

/* ----------------------------- memory ------------------------------*/
void	exit_p(t_pipex *pipex, int status);
int		fd_is_valid(int fd);

/* ------------------------------ init -------------------------------*/
t_pipex	*prepare_pipex(int ac, char **av, char **env);
void	get_env_paths(t_pipex *pipex, char **env);
t_pipex	*init_pipex(char **env);
int		b_input_params(t_pipex *pipex, char **av, int ac);

/* ----------------------------- execute -----------------------------*/
int		exec_cmds(t_pipex *pipex);

/* --------------------------- exec helpers --------------------------*/
void	open_out(t_pipex *pipex);
void	open_dup_in(t_pipex *pipex, int fd[2]);
void	open_dup_out(t_pipex *pipex);
char	*get_command_path(t_pipex *pipex, int i);
void	close_two(int fd[2], int i);

/* --------------------------- here_doc ------------------------------*/
void	gen_filename_heredoc(t_pipex *pipex);
void	gen_here_doc(t_pipex *pipex);

#endif