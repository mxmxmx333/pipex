/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:44:17 by mbonengl          #+#    #+#             */
/*   Updated: 2024/09/06 17:00:49 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static unsigned long	get_seed(void)
{
	int				uninitialized_var;
	unsigned long	seed;

	seed = (unsigned long)&uninitialized_var;
	return (seed);
}

static unsigned long	get_random_number(unsigned long seed)
{
	seed = (seed * 1103515245 + 12345) & 0x7fffffff;
	return (seed);
}

static char	get_random_alphanum(unsigned long seed, int i)
{
	char			c;

	c = get_random_number((seed / (i * i + 1))) % 62;
	if (c < 10)
		return (c + '0');
	else if (c < 36)
		return (c - 10 + 'A');
	else
		return (c - 36 + 'a');
}

void	gen_filename_heredoc(t_pipex *pipex)
{
	char	*filename;
	int		i;

	i = -1;
	filename = ft_calloc(11, sizeof(char));
	if (!filename)
		return (perror("calloc failed"), exit_p(pipex, 1));
	while (++i < 10)
		filename[i] = get_random_alphanum(get_seed(), i);
	free(pipex->inf);
	pipex->inf = ft_strjoin("/tmp/here_doc_", filename);
	free(filename);
}
