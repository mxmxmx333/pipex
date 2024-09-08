/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:40:52 by mbonengl          #+#    #+#             */
/*   Updated: 2024/09/08 10:44:53 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	input_file(t_pipex *pipex, char **av)
{
	int	i;

	i = 2;
	pipex->inf = ft_strdup(av[1]);
	if (!pipex->inf)
		return (ft_error(pipex, ERR_MALLOC, NULL, 1), 0);
	return (i);
}

int	b_input_params(t_pipex *pipex, char **av, int ac)
{
	int	i;
	int	rev_offs;

	rev_offs = input_file(pipex, av);
	i = rev_offs - 1;
	pipex->cmds = (char ***)ft_calloc(ac - rev_offs + 1, sizeof(char **));
	if (!pipex->cmds)
		return (ft_error(pipex, ERR_MALLOC, NULL, 1), 1);
	while (++i < ac - 1)
	{
		if (str_is_empty(av[i]))
			pipex->cmds[i - rev_offs] = emptystr();
		else
			pipex->cmds[i - rev_offs] = ft_split(av[i], ' ');
		if (!pipex->cmds[i - rev_offs])
			return (ft_error(pipex, ERR_MALLOC, NULL, 1), 1);
	}
	pipex->cmds_count = i - rev_offs;
	pipex->outf = ft_strdup(av[ac - 1]);
	if (!pipex->inf || !pipex->outf)
		return (ft_error(pipex, ERR_MALLOC, NULL, 1), 1);
	return (1);
}

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
}

t_pipex	*init_pipex(char **env)
{
	t_pipex	*pip;

	pip = (t_pipex *)ft_calloc(1, sizeof(t_pipex));
	if (!pip)
		ft_error(pip, ERR_MALLOC, "init_pipex", 1);
	pip->env = env;
	return (pip);
}

t_pipex	*prepare_pipex(int ac, char **av, char **env)
{
	t_pipex	*pipex;

	(void)ac;
	(void)av;
	pipex = init_pipex(env);
	get_env_paths(pipex, env);
	b_input_params(pipex, av, ac);
	return (pipex);
}
