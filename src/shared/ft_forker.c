/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:04:37 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/12 14:43:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_shared.h"

static int	ft_child(t_cmd_list *cmds, char **envp, int fd_out, int *fd_pipe);

int	ft_forker(t_cmd_list *cmds, char **envp, int fd_out)
{
	int	fd[2];
	int	pid;
	int	rtn;

	rtn = 0;
	if (pipe(fd) == -1)
		rtn = ft_error_handler("Can't pipe fds on pipex", errno);
	pid = fork();
	if (pid == -1)
		rtn = ft_error_handler("Can't fork process on pipex", errno);
	if (rtn >= 0)
	{
		if (pid == 0)
		{
			ft_child(cmds, envp, fd_out, fd);
		}
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	return (rtn);
}

static int	ft_child(t_cmd_list *cmds, char **envp, int fd_out, int *fd_pipe)
{
	int	rtn;

	rtn = 0;
	close(fd_pipe[0]);
	if (cmds->next)
		rtn = dup2(fd_pipe[1], 1);
	else
	{
		close(fd_pipe[1]);
		rtn = dup2(fd_out, 1);
	}
	rtn = execve(cmds->cmd.cmd_path, cmds->cmd.cmd_params, envp);
	if (rtn < 0)
		rtn = -1;
	else
		rtn = 0;
	return (rtn);
}
