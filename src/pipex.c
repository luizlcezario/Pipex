/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:50:03 by llima-ce          #+#    #+#             */
/*   Updated: 2021/12/21 15:47:53 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	execute_cmds(t_pipex *pipex, int *fd, int a, int fd_tmp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror_custom(pipex, "error to try fork");
	else if (pid == 0)
	{
		if (dup2(fd_tmp, STDIN_FILENO) == -1)
				perror_custom(pipex, "error to change the fd infile");
		if (a == pipex->cmd_num - 1)
		{
			if (dup2(pipex->fd.outfd, STDOUT_FILENO) == -1)
				perror_custom(pipex, "error to change the fd outfile");
		}
		else
		{
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				perror_custom(pipex,"error to change the fd infile");
		}
		if (execve(pipex->cmd[a]->path_cmd, pipex->cmd[a]->argv, pipex->envp)
			== -1)
			perror_custom(pipex,"error execve");
		close(fd[0]);
		return(0);
	}
	wait(&pipex->err_num);
	fd_tmp = fd[0];
	close(fd[1]);
	return (0);
}

void	pipex_exc(t_pipex *pipex)
{
	int	a;
	int fd[2];

	a = -1;
	while (++a < pipex->cmd_num)
	{
		if(pipe(fd) == -1)
			perror_custom(pipex,"error to try pipe");
		if(execute_cmds(pipex, fd, a, pipex->fd.infd) == -1)
			perror_custom(pipex,"error to execute the commands");
	}
}
