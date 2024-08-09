/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:02:26 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/09 11:42:02 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "errors.h"
# include "libft.h"
# include <fcntl.h> // open, O_RDONLY, O_WRONLY, O_CREAT, O_TRUNC
# include <unistd.h> // write, close, fork, execve, pipe, dup2, access, open

typedef struct s_pipex
{
	char	***cmds;
	char	*inf;
	char	*outf;
	char	**paths;
	char	**cmdpaths;
}	t_pipex;

/* ----------------- error handling ------------------*/
void	ft_error(t_pipex *pipex, char *error, char *place);
int		check_files(t_pipex *pipex);
int		input_params(t_pipex *pipex, char **av);
int		check_commands(t_pipex *pipex);

/* --------------------- memory ----------------------*/
void	exit_p(t_pipex *pipex, int status);

/* ---------------------- init -----------------------*/
void	get_env_paths(t_pipex *pipex, char **env);
t_pipex	*init_pipex(void);
t_pipex	*prepare_pipex(int ac, char **av, char **env);

/* --------------------- execute ---------------------*/
void	exec_cmds(t_pipex *pipex, char **envp);

/* ---------------------- test -----------------------*/
void	print_paths(t_pipex *pipex); // testing.c
void	read_pipex(t_pipex *pipex);

#endif