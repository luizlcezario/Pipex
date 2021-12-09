/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:40:01 by llima-ce          #+#    #+#             */
/*   Updated: 2021/12/08 21:56:34 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->err_num = 0;
	pipex->argc = argc;
	pipex->cmd_num = argc - 3;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->fd.infd = open(pipex->argv[1], O_RDONLY);
	pipex->fd.outfd  = open(pipex->argv[4], O_RDWR, O_CREAT);
	init_cmds(pipex);
	init_pipe(pipex);
}