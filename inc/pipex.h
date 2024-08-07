/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:02:26 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/05 20:45:44 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "errors.h"
# include "libft.h"
# include <unistd.h> // write, close, fork, execve, pipe, dup2, access, open

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	char	*inf;
	char	*outf;
	char	**paths;
}	t_pipex;

/* ----------------- error handling ------------------*/
void	ft_error(t_pipex *pipex, char *error);
int		check_files(t_pipex *pipex);
int		input_params(t_pipex *pipex, char **av);
int		check_commands(t_pipex *pipex);

/* --------------------- memory ----------------------*/
void	exit_p(t_pipex *pipex, int status);

/* ---------------------- init -----------------------*/
void	get_env_paths(t_pipex *pipex, char **env);
t_pipex	*init_pipex(void);
t_pipex	*prepare_pipex(int ac, char **av, char **env);

/* ---------------------- test -----------------------*/
void	print_paths(t_pipex *pipex); // testing.c

#endif