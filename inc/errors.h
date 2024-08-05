/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:06:20 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/05 16:23:40 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_WRONG_ARG "Error: Wrong number of arguments\n"
# define ERR_NO_FILE "Error: No such file or directory\n"
# define ERR_WRONG_FORMAT_IN "Error: Wrong format: infile\n"
# define ERR_WRONG_FORMAT_OUT "Error: Wrong format: outfile\n"
# define ERR_WRONG_FORMAT_CMD1 "Error: Wrong format: cmd1\n"
# define ERR_WRONG_FORMAT_CMD2 "Error: Wrong format: cmd2\n"
# define ERR_NO_PERM_IN "Error: >Read permission< denied: infile\n"
# define ERR_NO_PERM_OUT "Error: >Write permission< denied: outfile\n"
# define ERR_NO_PERM_CMD1 "Error: >Execute permission< denied: cmd1\n"
# define ERR_NO_PERM_CMD2 "Error: >Execute permission< denied: cmd2\n"
# define ERR_CMD_NOT_FOUND "Error: command not found\n"
# define ERR_CMD_NOT_EXEC "Error: command not executable\n"
# define ERR_PIPE "Error: Pipe failed\n"
# define ERR_FORK "Error: Fork failed\n"
# define ERR_DUP2 "Error: Dup2 failed\n"
# define ERR_EXECVE "Error: Execve failed\n"
# define ERR_OPEN "Error: Open failed\n"
# define ERR_CLOSE "Error: Close failed\n"
# define ERR_MALLOC "Error: Malloc failed\n"
# define ERR_PATHS "Failed to get PATH\n"

#endif