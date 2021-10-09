/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:40:04 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/09 02:31:12 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	child_proc(char *infile, t_cmd_list *cmd, char **envp, int pos);
static void	parent_proc(char *outfile, t_cmd_list *cmd, char **envp, int pos);
static void	ft_close_pipes(t_cmd_list *cmds);

int	ft_pipex(t_vars *vars, t_cmd_list *cmds, char **envp)
{
	int	pid;
	int last_cmd_pos;
	
	last_cmd_pos = ft_get_list_len(cmd);
	pid = fork();
	if (pid == -1)
		ft_error_handler("Can't fork process on pipex", errno);
	if (pid == 0)
		child_proc(vars->infile, cmds, envp, last_cmd_pos - 1);
	waitpid(pid, NULL, 0);
	parent_proc(vars->outfile, ft_get_last_cmd(vars->commands), envp);
	ft_close_pipes(cmds);
	return (0);
}

static void	ft_breeder(char *infile, t_cmd_list *cmds, char **envp, int pos)
{
	int	pid;
	
	if (pos > 0)
		ft_breeder(infile, cmds, envp, pos -1);
	if (cmds->next->next)
	{
		pid = fork();
		if (pid == -1)
			ft_error_handler("Can't fork process on pipex", errno);
		if (pid == 0)
			child_proc(fd_in, cmds, envp, pos - 1);
		waitpid(pid, NULL, 0);
		cmds = cmds->next;
	}
}

static void	child_proc(char *infile, t_cmd_list *cmds, char **envp, int pos)
{
	int	fd_in;

	fd_in = 0;
	if (pos == 0)
	{
		fd_in = open(infile, O_RDONLY, 0777);
		if (fd_in == -1)
			ft_error_handler("Can't open input file on pipex", errno);
	}
	dup2(cmds->cmd.fd_pipe[1], 1);
	if (cmds->cmd.anterior_pipe)
	{
		dup2(cmds->cmd.anterior_pipe[0], 0);
		close(cmds->cmd.anterior_pipe[1]);
	}
	else
	{
		dup2(fd_in, 0);
	}
	close(cmds->cmd.fd_pipe[0]);
	execve(cmds->cmd.cmd_path, cmds->cmd.cmd_params, envp);
}

static void	parent_proc(char *outfile, t_cmd_list *cmds, char **envp, int pos)
{
	int		fd_out;

	fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		ft_error_handler("Can't open input file on pipex", errno);
	dup2(cmds->cmd.anterior_pipe[0], 0);
	dup2(fd_out, 1);
	close(cmds->cmd.anterior_pipe[1]);
	execve(cmds->cmd.cmd_path, cmds->cmd.cmd_params, envp);
}

static void	ft_close_pipes(t_cmd_list *cmds)
{
	while (cmds)
	{
		close(cmds->cmd.fd_pipe[0]);
		close(cmds->cmd.fd_pipe[1]);
		cmds = cmds->next;
	}
}
