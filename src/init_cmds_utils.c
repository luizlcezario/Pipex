/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:56:02 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/04 18:55:09 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	split_paths(t_pipex *pipex)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (path == NULL)
	{
		path = ft_strnstr(pipex->envp[i], "PATH=", 5);
		if (pipex->envp[i] == NULL)
			return (10);
		i++;
	}
	path = ft_strchr(path, '/');
	pipex->paths = ft_split(path, ':');
	return (0);
}
