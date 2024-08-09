/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:40:52 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/09 12:19:39 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_env_paths(t_pipex *pipex, char **env)
{
	int	i;

	if (!env)
		return ;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			pipex->paths = ft_split(env[i] + 5, ':');
			break ;
		}
		i++;
	}
	if (!pipex->paths)
		ft_error(pipex, ERR_PATHS, NULL);
}

t_pipex	*init_pipex(void)
{
	t_pipex	*pip;

	pip = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	if (!pip)
		ft_error(pip, ERR_MALLOC, "init_pipex");
	return (pip);
}

t_pipex	*prepare_pipex(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	(void)ac;
	(void)av;
	pipex = init_pipex();
	get_env_paths(pipex, env);
	input_params(pipex, av);
	check_files(pipex);
	check_commands(pipex);
	ft_putstr_fd("pipex initialized\n", 1);
	return (pipex);
}