/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:54:37 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/04 18:56:28 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	char	**teste;

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
