/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:50:51 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/08 15:04:28 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_array(char **array, char *name)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	printf("%s\n", name);
	while (array[i])
	{
		printf("[%d]: %s\n", i, array[i]);
		i++;
	}
}

void	read_pipex(t_pipex *pipex)
{
	print_array(pipex->cmd1, "cmd1");
	print_array(pipex->cmd2, "cmd2");
	printf("inf: %s\n", pipex->inf);
	printf("outf: %s\n", pipex->outf);
	printf("p1: %s\n", pipex->p1);
	printf("p2: %s\n", pipex->p2);
}

void	print_paths(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->paths[i])
	{
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(pipex->paths[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
