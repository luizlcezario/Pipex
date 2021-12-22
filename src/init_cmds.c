/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:50:53 by llima-ce          #+#    #+#             */
/*   Updated: 2021/12/21 16:21:37 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmds(t_pipex *pipex)
{
	int	i;

	pipex->err_num = split_paths(pipex);
	if (pipex->err_num)
		perror_custom(pipex, "Some goes wrong when the programs tries to find \
					the paths of the programs to run the pipex");
	pipex->cmd = malloc((pipex->cmd_num + 1) * sizeof(t_cmd *));
	if (!pipex->cmd)
		perror_custom(pipex, "the allocation of memory goes wrong");
	pipex->cmd[pipex->cmd_num] = NULL;
	i = 0;
	while(i < pipex->cmd_num)
	{
		pipex->err_num = find_cmd(pipex, i);
		if (pipex->err_num)
			perror_custom(pipex, "something goes wrong when take the cmds");
		pipex->err_num = testing_acess(pipex, i);
		if (pipex->err_num)
			perror_custom(pipex, "something goes wrong when testing the cmds");
		i++;
	}
}
