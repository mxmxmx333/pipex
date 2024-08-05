/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:19:39 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/05 16:21:51 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_files(t_pipex *pipex)
{
	if (access(pipex->inf, F_OK) == -1)
		return (ft_error(pipex, ERR_NO_FILE), 0);
	if (access(pipex->inf, R_OK) == -1)
		return (ft_error(pipex, ERR_NO_PERM_IN), 0);
	if (access(pipex->outf, F_OK) == -1)
		return (ft_error(pipex, ERR_NO_FILE), 0);
	if (access(pipex->outf, W_OK) == -1)
		return (ft_error(pipex, ERR_NO_PERM_OUT), 0);
	return (1);
}