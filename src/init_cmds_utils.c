/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:56:02 by llima-ce          #+#    #+#             */
/*   Updated: 2021/12/21 18:27:02 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		split_paths(t_pipex *pipex)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while(path == NULL)
	{
		path = ft_strnstr(pipex->envp[i], "PATH=", 5);
		if (pipex->envp[i] == NULL)
			return	(10);
		i++;
	}
	path = ft_strchr(path, '/');
	pipex->paths = ft_split(path, ':');
	return (0);
}

int		find_cmd(t_pipex *pipex, int i)
{
	pipex->cmd[i] = malloc(1 * sizeof(t_cmd));
	if(!pipex->cmd[i])
		return (7);
	pipex->cmd[i]->argv = ft_split(pipex->argv[2 + i], ' ');
	return (0);
}

int		testing_acess(t_pipex *pipex, int a)
{
	int		i;

	i = 0;
	while (pipex->paths[i])
	{
		pipex->cmd[a]->path_cmd = ft_formatf("%s/%s",pipex->paths[i],
				pipex->cmd[a]->argv[0]);
		if (access(pipex->cmd[a]->path_cmd, X_OK) == 0)
			return (0);
		free_ptr((void **)&pipex->cmd[a]->path_cmd);
		i++;
	}
	return (2);
}
