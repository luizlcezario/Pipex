/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:13:01 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 22:04:52 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_ptr(void **fread)
{
	if (*fread != NULL)
	{
		free(*fread);
		*fread = NULL;
	}
}

void	perror_custom(t_pipex *pipex, char *error_msg, int flag)
{
	if (flag)
		pipex->cmd_num = flag;
	if (pipex->err_num != 0)
		free_all(pipex);
	exit(ft_error(pipex->err_num, error_msg));
}

void	free_all(t_pipex *pipex)
{
	int	a;
	int	b;

	a = -1;
	while (++a < pipex->cmd_num)
	{
		b = -1;
		if (pipex->cmd[a] != NULL)
		{
			while (pipex->cmd[a]->argv[++b] != NULL)
				free_ptr((void **)&pipex->cmd[a]->argv[b]);
			free_ptr((void **)&pipex->cmd[a]->argv);
			free_ptr((void **)&pipex->cmd[a]->path_cmd);
			free_ptr((void **)&pipex->cmd[a]);
		}
	}
	a = -1;
	while (pipex->paths[++a] != NULL)
		free_ptr((void **)&pipex->paths[a]);
	free_ptr((void **)&pipex->paths);
	free_ptr((void **)&pipex->cmd);
	close (pipex->fd.infd);
	close (pipex->fd.outfd);
}
