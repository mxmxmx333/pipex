/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:23:21 by mbonengl          #+#    #+#             */
/*   Updated: 2024/09/06 17:01:14 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**emptystr(void)
{
	char	**empty;

	empty = (char **)ft_calloc(2, sizeof(char *));
	if (!empty)
		return (NULL);
	empty[0] = ft_strdup("");
	if (!empty[0])
	{
		free(empty);
		return (NULL);
	}
	return (empty);
}

int	fd_is_valid(int fd)
{
	char	*buf;

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

void	errmsg(t_pipex *pipex, char *error, char *place)
{
	char	*message;

	message = ft_strjoin_three(error, place, "\n");
	if (!message)
		return (ft_error(pipex, ERR_MALLOC, NULL, 1));
	ft_putstr_fd(message, 2);
	free(message);
}

// void	errmsg(char *error, char *place)
// {
// 	ft_putstr_fd(error, 2);
// 	if (place)
// 		ft_putstr_fd(place, 2);
// 	ft_putchar_fd('\n', 2);
// 	perror(NULL);
// }
