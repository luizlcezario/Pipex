/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:13:38 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 15:27:58 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_custom(int fd1, int fd2, char *cmd, t_pipex *pipex)
{
	if (dup2(fd1, fd2) == -1)
		perror_custom(pipex, cmd, 0);
}

void	command_not_found(t_pipex *pipex, char *cmd)
{
	ft_printf("%s: command not found\n", cmd);
	pipex->err_num = 0;
}

int	find_cmd(t_pipex *pipex, int i)
{
	pipex->cmd[i] = malloc(1 * sizeof(t_cmd));
	if (!pipex->cmd[i])
		return (7);
	pipex->cmd[i]->argv = ft_split_cmds(pipex->argv[2 + i]);
	return (0);
}

int	testing_acess(t_pipex *pipex, int a)
{
	int	i;

	i = 0;
	while (pipex->paths[i])
	{
		pipex->cmd[a]->path_cmd = ft_formatf("%s/%s", pipex->paths[i],
				pipex->cmd[a]->argv[0]);
		if (access(pipex->cmd[a]->path_cmd, X_OK) == 0)
			return (0);
		free_ptr((void **)&pipex->cmd[a]->path_cmd);
		i++;
	}
	return (2);
}
