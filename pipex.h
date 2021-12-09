/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:20:24 by llima-ce          #+#    #+#             */
/*   Updated: 2021/12/09 21:52:16 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft/libft.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef struct s_cmd
{
		char	*path_cmd;
		char	**argv;
}		t_cmd;

typedef struct s_fd
{
	int		infd;
	int		outfd;
	int		tmpfd;
	int		pipefd[2];
}		t_fd;

typedef struct s_pipex
{
		int		err_num;
		int		argc;
		int		cmd_num;
		char	**envp;
		char	**argv;
		char	**paths;
		t_cmd	**cmd;
		t_fd	fd;
}		t_pipex;

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp);

void	pipex_exc(t_pipex *pipex);

void	init_cmds(t_pipex *pipex);
int		testing_acess(t_pipex *pipex, int a);
int		find_cmd(t_pipex *pipex, int i);
int		split_paths(t_pipex *pipex);

void	init_pipe(t_pipex *pipex);
void	pipex_exc(t_pipex *pipex);
void	perror_custom(t_pipex *pipex, char *error_msg);
#endif