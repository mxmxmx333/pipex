/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:51:04 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/05 19:38:28 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "stdio.h" // ACHTUNG ENTFERNEN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void	read_pipex(t_pipex *pipex)
{
	printf("cmd1: %s\n", pipex->cmd1);
	printf("cmd2: %s\n", pipex->cmd2);
	printf("inf: %s\n", pipex->inf);
	printf("outf: %s\n", pipex->outf);
}

int main(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	if (ac != 5)
		return (ft_error(NULL, ERR_WRONG_ARG), 1);
	pipex = prepare_pipex(ac, av, env);
	read_pipex(pipex);
	// Funtion that checks the input parameters, and returns a struct with the input parameters
	/* if (!ft_check_params(ac, av, &pipex))
		return (1); */
	// Function that checks if the input and output files are accessible
	/* if (!check_files(pipex))
		return (1); */
	// Function that executes the commands
	/* exec_cmds(pipex); */
	printf("Word Count: %d\n", ft_countwords_whitespace(av[1]));
	exit_p(pipex, 0);
	return (0);
}
