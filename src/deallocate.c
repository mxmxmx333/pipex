/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:10:00 by mbonengl          #+#    #+#             */
/*   Updated: 2024/09/06 16:05:52 by mbonengl         ###   ########.fr       */
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
		if (pipex->outf)
			free(pipex->outf);
		if (pipex->paths)
			ft_free_split(pipex->paths);
		if (pipex->limiter)
		{
			if (ft_strcmp(pipex->inf, "here_doc"))
				unlink(pipex->inf);
			free(pipex->limiter);
		}
		if (pipex->inf)
			free(pipex->inf);
		if (pipex->cmds)
			ft_free_split_mother(pipex->cmds);
	}
	if (pipex)
		free(pipex);
	exit(status);
}
