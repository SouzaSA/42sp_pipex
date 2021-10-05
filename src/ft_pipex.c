/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:40:04 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 21:13:42 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	child_proc(char *infile, t_cmd_list *cmds, char **envp, int *fd);
static void	parent_proc(char *outfile, t_cmd_list *cmd, char **envp, int *fd);

int	ft_pipex(t_vars *vars, char **envp)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		ft_error_handler("Can't pipe fds on pipex", errno);
	pid = fork();
	if (pid == -1)
		ft_error_handler("Can't fork process on pipex", errno);
	if (pid == 0)
		child_proc(vars->infile, vars->commands, envp, fd);
	waitpid(pid, NULL, 0);
	parent_proc(vars->outfile, ft_get_last_cmd(vars->commands), envp, fd);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

static void	child_proc(char *infile, t_cmd_list *cmds, char **envp, int *fd)
{
	int			fd_in;
	t_cmd_list	*last_cmd;

	last_cmd = ft_get_last_cmd(t_cmd_list *cmd_list);
	fd_in = open(infile, O_RDONLY, 0777);
	if (fd_in == -1)
		ft_error_handler("Can't open input file on pipex", errno);
	dup2(fd[1], 1);
	dup2(fd_in, 0);
	close(fd[0]);
	execve(cmds->cmd_path, cmds->cmd, envp);
	while (cmds->nex != last_cmd)
	{
		dup2(fd[1], 1);
		dup2(fd_in, 0);
		close(fd[0]);
		execve(cmds->cmd_path, cmds->cmd, envp);
		cmds = cmds->next;
	}
}

void	parent_proc(char *outfile, t_cmd_list *cmd, char **envp, int *fd)
{
	int		fd_out;

	fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		ft_error_handler("Can't open input file on pipex", errno);
	dup2(fd[0], 0);
	dup2(fd_out, 1);
	close(fd[1]);
	execve(cmd->cmd_path, cmd->cmd, envp);
}
