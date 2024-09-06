/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 11:18:10 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/25 15:21:24 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	gen_here_doc(t_pipex *pipex)
{
	int		fd;
	char	*line;

	if (!pipex->limiter)
		return ;
	gen_filename_heredoc(pipex);
	fd = open(pipex->inf, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return (perror("open failed"), exit_p(pipex, 1));
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			continue ;
		if (!ft_strcmp(line, pipex->limiter))
		{
			free(line);
			get_next_line(-1);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
}
