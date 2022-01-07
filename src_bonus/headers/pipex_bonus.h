/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:20:24 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 22:05:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft_bonus.h"
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_cmd
{
	char	*path_cmd;
	char	**argv;
}			t_cmd;

typedef struct s_fd
{
	int	infd;
	int	outfd;
	int	tmpfd;
	int	pipefd[2];
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
}	t_pipex;

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **envp);

void	pipex_exc(t_pipex *pipex);

void	init_cmds(t_pipex *pipex);
int		testing_acess(t_pipex *pipex, int a);
int		find_cmd(t_pipex *pipex, int i);
int		split_paths(t_pipex *pipex);

void	free_all(t_pipex *pipex);
void	free_ptr(void **fread);
void	init_pipe(t_pipex *pipex);
void	pipex_exc(t_pipex *pipex);
void	perror_custom(t_pipex *pipex, char *error_msg, int flag);
void	dup_custom(int fd1, int fd2, char *cmd, t_pipex *pipex);
void	command_not_found(t_pipex *pipex, char *cmd);
char	**ft_split_cmds(char const *s);
#endif