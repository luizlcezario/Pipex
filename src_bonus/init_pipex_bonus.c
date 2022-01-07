/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:40:01 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 22:04:52 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->err_num = 0;
	pipex->argc = argc;
	pipex->cmd_num = argc - 3;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->fd.infd = open(pipex->argv[1], O_RDONLY);
	pipex->fd.outfd = open(pipex->argv[argc - 1], O_CREAT | O_WRONLY
			| O_TRUNC, 0777);
	if (pipex->fd.infd == -1 || pipex->fd.outfd == -1)
		perror_custom(pipex, "error to try open file", 0);
	init_cmds(pipex);
}
