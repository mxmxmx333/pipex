/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 10:06:20 by mbonengl          #+#    #+#             */
/*   Updated: 2024/08/05 20:49:23 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_WRONG_ARG "Error: Wrong number of arguments "
# define ERR_NO_FILE "Error: No such file or directory: "
# define ERR_NO_PERM_IN "Error: >Read permission< denied: "
# define ERR_NO_PERM_OUT "Error: >Write permission< denied: "
# define ERR_NO_PERM_CMD "Error: >Execute permission< denied: "
# define ERR_CMD_NOT_FOUND "Error: command not found: "
# define ERR_PIPE "Error: Pipe failed "
# define ERR_FORK "Error: Fork failed "
# define ERR_DUP2 "Error: Dup2 failed "
# define ERR_EXECVE "Error: Execve failed "
# define ERR_OPEN "Error: Open failed "
# define ERR_CLOSE "Error: Close failed "
# define ERR_MALLOC "Error: Malloc failed "
# define ERR_PATHS "Failed to get PATH "

#endif