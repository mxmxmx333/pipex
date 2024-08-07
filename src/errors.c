/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:23:21 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/05 20:47:47 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(t_pipex *pipex, char *error, char *place)
{
	ft_putstr_fd(error, 2);
	if (place)
		ft_putstr_fd(place, 2);
	ft_putchar_fd('\n', 2);
	exit_p(pipex, 1);
}
