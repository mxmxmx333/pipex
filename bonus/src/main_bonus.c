/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:51:04 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/16 11:24:53 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	if (ac < 5)
		return (ft_error(NULL, ERR_WRONG_ARG, "(infile cmd1 (...) cmdx outfile)", 0), 1);
	// Funtion that checks the input parameters, and returns a struct with the input parameters
	pipex = prepare_pipex(ac, av, env);
	exec_cmds(pipex);
	exit_p(pipex, 0);
	return (0);
}
