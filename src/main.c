/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:51:04 by mbonengl          #+#    #+#             */
/*   Updated: 2024/09/02 14:34:07 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	*pipex;
	int		status;

	if (ac != 5)
		return (ft_putstr_fd(ERR_WRONG_ARG, 2), ft_putstr_fd(USAGE, 2), 2);
	pipex = prepare_pipex(ac, av, env);
	status = exec_cmds(pipex);
	exit_p(pipex, status);
	return (status);
}
