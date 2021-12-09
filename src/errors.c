/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:13:01 by llima-ce          #+#    #+#             */
/*   Updated: 2021/12/09 20:37:29 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_custom(t_pipex *pipex, char *error_msg)
{
	exit(ft_error(pipex->err_num, error_msg));
}

void	free_all(t_pipex *pipex)
{

	close (pipex->fd.infd);
	close (pipex->fd.outfd);
	exit (0);
}