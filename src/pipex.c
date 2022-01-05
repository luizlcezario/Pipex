/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:50:03 by llima-ce          #+#    #+#             */
/*   Updated: 2022/01/05 15:58:18 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	testing_programing(t_pipex *pipex, int a)
{
	if (a < pipex->cmd_num)
	{
		if (find_cmd(pipex, a) != 0)
			pipex->err_num = 127;
		if (testing_acess(pipex, a) != 0)
			pipex->err_num = 127;
	}
}

static void	pipe_change(t_pipex *pipex, int *fd, int a, int fd_tmp)
{
	close(fd[0]);
	dup_custom(fd_tmp, STDIN_FILENO, "error infile", pipex);
	if (a == pipex->cmd_num - 1)
		dup_custom(pipex->fd.outfd, STDOUT_FILENO, "error outfile",
			pipex);
	else
		dup_custom(fd[1], STDOUT_FILENO, "error infile", pipex);
	if (execve(pipex->cmd[a]->path_cmd, pipex->cmd[a]->argv,
			pipex->envp) == -1)
		perror_custom(pipex, "error execve", 0);
}

static int	execute_cmds(t_pipex *pipex, int *fd, int a, int fd_tmp)
{
	pid_t	pid;

	testing_programing(pipex, a);
	pid = fork();
	if (pid == -1)
		perror_custom(pipex, "error to try fork", 0);
	else if (pid == 0)
	{
		if (pipex->err_num == 0)
		{
			pipe_change(pipex, fd, a, fd_tmp);
		}
		else
			command_not_found(pipex, pipex->cmd[a]->argv[0]);
		return (0);
	}
	wait(&pipex->err_num);
	close(pipex->fd.infd);
	pipex->fd.infd = fd[0];
	close(fd[1]);
	return (0);
}

void	pipex_exc(t_pipex *pipex)
{
	int	a;
	int	fd[2];

	a = 0;
	while (a < pipex->cmd_num)
	{
		if (pipe(fd) == -1)
			perror_custom(pipex, "error to try pipe", 0);
		if (execute_cmds(pipex, fd, a, pipex->fd.infd) == -1)
			perror_custom(pipex, "error to execute the commands", 0);
		a++;
	}
}
