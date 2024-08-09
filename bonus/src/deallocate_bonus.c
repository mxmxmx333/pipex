/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:10:00 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/08 13:32:49 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	if (split)
		free(split);
}

void	exit_p(t_pipex *pipex, int status)
{
	if (pipex)
	{
		if (pipex->cmd1)
			ft_free_split(pipex->cmd1);
		if (pipex->cmd2)
			ft_free_split(pipex->cmd2);
		if (pipex->inf)
			free(pipex->inf);
		if (pipex->outf)
			free(pipex->outf);
		if (pipex->paths)
			ft_free_split(pipex->paths);
		if (pipex->p1)
			free(pipex->p1);
		if (pipex->p2)
			free(pipex->p2);
	}
	free(pipex);
	exit(status);
}
