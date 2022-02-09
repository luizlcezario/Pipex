/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:50:53 by llima-ce          #+#    #+#             */
/*   Updated: 2022/02/09 11:35:25 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmds(t_pipex *pipex)
{
	pipex->err_num = split_paths(pipex);
	if (pipex->err_num)
		perror_custom(pipex, "Some goes wrong when the programs tries to find \
					the paths of the programs to run the pipex", 0);
	pipex->cmd = malloc((pipex->cmd_num + 1) * sizeof(t_cmd *));
	if (!pipex->cmd)
		perror_custom(pipex, "the allocation of memory goes wrong", 0);
	pipex->cmd[pipex->cmd_num] = NULL;
}
