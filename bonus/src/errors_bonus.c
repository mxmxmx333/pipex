/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:23:21 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/14 09:55:48 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	fd_is_valid(int fd)
{
	char *buf;
	return (read(fd, &buf, 0) == 0 || errno != EBADF);
}

void	ft_error(t_pipex *pipex, char *error, char *place, int exit_status)
{
	ft_putstr_fd(error, 2);
	if (place)
		ft_putstr_fd(place, 2);
	ft_putchar_fd('\n', 2);
	exit_p(pipex, exit_status);
}

