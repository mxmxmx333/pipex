/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:10:00 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/15 19:02:48 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"


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

static void	ft_free_split_mother(char ***split_mother)
{
	int	i;

	i = 0;
	while (split_mother[i])
	{
		ft_free_split(split_mother[i]);
		i++;
	}
	if (split_mother)
		free(split_mother);
}

void	exit_p(t_pipex *pipex, int status)
{
	if (pipex)
	{
		if (pipex->cmds)
			ft_free_split_mother(pipex->cmds);
		if (pipex->inf)
			free(pipex->inf);
		if (pipex->outf)
			free(pipex->outf);
		if (pipex->paths)
			ft_free_split(pipex->paths);
		if (pipex->cmd_p)
			ft_free_split(pipex->cmd_p);
	}
	free(pipex);
	exit(status);
}
