/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 22:54:37 by llima-ce          #+#    #+#             */
/*   Updated: 2021/12/09 22:28:38 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
* access
◦ open
◦ unlink
◦ close
◦ read
◦ write
◦ malloc
◦ waitpid
◦ wait
◦ free
◦ pipe
◦ dup
◦ dup2
◦ execve
◦ fork
◦ perror
◦ strerror
◦ exit
/home/coder/.vscode-server/bin/ccbaa2d27e38e5afa3e5c21c1c7bef4657064247/bin:/home/coder/.vscode-server/bin/ccbaa2d27e38e5afa3e5c21c1c7bef4657064247/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
*/

int	main(int argc,char **argv, char **envp)
{
	t_pipex	pipex;

	if(argc == 5)
	{
		init_pipex(&pipex, argc, argv, envp);
		pipex_exc(&pipex);
		execve(pipex.cmd[1]->path_cmd, pipex.cmd[1]->argv, pipex.envp);
		exit(0);
	}
	else if (argc > 5)
		exit(ft_error(22, "Too many argument!"));
	else
		exit(ft_error(22, "Too few argument!"));
}

// after fork the child process have the id = 0