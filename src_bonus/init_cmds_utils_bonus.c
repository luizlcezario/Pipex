/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:56:02 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 22:04:52 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
