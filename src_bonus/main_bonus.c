/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:54:37 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 22:06:08 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc >= 5)
	{
		init_pipex(&pipex, argc, argv, envp);
		pipex_exc(&pipex);
		free_all(&pipex);
		exit(0);
	}
	else
		exit(ft_error(22, "Too few argument!"));
}
