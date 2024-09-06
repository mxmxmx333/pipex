/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:06:20 by mbonengl          #+#    #+#             */
/*   Updated: 2024/09/06 18:58:17 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_WRONG_ARG "Error: Wrong number of arguments \n"
# define ERR_NO_FILE "Error: No such file or directory: \n"
# define ERR_NO_READ "Error: >Read permission< denied: \n"
# define ERR_NO_WRITE "Error: >Write permission< denied: \n"
# define ERR_NO_EXEC "Error: >Execute permission< denied: \n"
# define ERR_CMD_NOT_FOUND "Error: Command not found"
# define ERR_PIPE "Error: Pipe failed \n"
# define ERR_FORK "Error: Fork failed \n"
# define ERR_DUP2 "Error: Dup2 failed \n"
# define ERR_EXECVE "Error: Execve failed \n"
# define ERR_OPEN "Error: Open failed \n"
# define ERR_CLOSE "Error: Close failed \n"
# define ERR_MALLOC "Error: Malloc failed \n"
# define ERR_PATHS "Failed to get PATH \n"
# define USAGE "Usage: ./pipex file1 cmd1 cmd2 file2\n"

#endif