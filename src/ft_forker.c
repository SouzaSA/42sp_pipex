/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:04:37 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/04 09:28:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	ft_child(t_vars *vars, int *fd_pipe);
static void	ft_cleaner_exit(t_vars *vars, char *cmd_path, char **cmd_params);
static void	ft_parent(t_vars *vars, int *fd_pipe, int pid);

int	ft_forker(t_vars *vars)
{
	int		fd[2];
	int		pid;
	int		rtn;

	rtn = 0;
	if (pipe(fd) == -1)
		rtn = ft_error_msg(NULL);
	pid = fork();
	if (pid == -1)
		rtn = ft_error_msg(NULL);
	if (rtn == 0)
	{
		if (pid == 0)
			ft_child(vars, fd);
		ft_parent(vars, fd, pid);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	return (rtn);
}

static void	ft_child(t_vars *vars, int *fd_pipe)
{
	int		fd_in;
	char	*cmd_path;
	char	**cmd_params;

	close(fd_pipe[0]);
	if (vars->arg_idx == vars->argc - 2)
		ft_cleaner_exit(vars, NULL, NULL);
	if (vars->arg_idx == 2)
	{
		fd_in = open(vars->argv[1], O_RDONLY);
		if (fd_in < 0)
			ft_cleaner_exit(vars, NULL, NULL);
		dup2(fd_in, 0);
		close(fd_in);
	}
	cmd_params = ft_params_split(vars->argv[vars->arg_idx], ' ');
	cmd_path = ft_get_cmd_path(cmd_params[0], vars->env_path);
	dup2(fd_pipe[1], 1);
	close(fd_pipe[1]);
	if (cmd_path)
		execve(cmd_path, cmd_params, vars->envp);
	ft_error_msg(NULL);
	ft_cleaner_exit(vars, cmd_path, cmd_params);
}

static void	ft_parent(t_vars *vars, int *fd_pipe, int pid)
{
	int		fd_out;
	char	*cmd_path;
	char	**cmd_params;
	char	*outfile;

	close(fd_pipe[1]);
	if (vars->arg_idx == vars->argc - 2)
	{
		waitpid(pid, NULL, 0);
		outfile = vars->argv[vars->argc - 1];
		fd_out = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		if (fd_out < 0)
		{
			ft_error_msg(NULL);
			ft_cleaner_exit(vars, NULL, NULL);
		}
		cmd_params = ft_params_split(vars->argv[vars->arg_idx], ' ');
		cmd_path = ft_get_cmd_path(cmd_params[0], vars->env_path);
		if (cmd_path)
		{
			dup2(fd_out, 1);
			execve(cmd_path, cmd_params, vars->envp);
		}
		ft_cleaner_exit(vars, cmd_path, cmd_params);
	}
}

static void	ft_cleaner_exit(t_vars *vars, char *cmd_path, char **cmd_params)
{
	int	i;

	i = 0;
	ft_cleaner_strstr(vars->env_path);
	vars->env_path = NULL;
	if (cmd_path)
		free(cmd_path);
	if (cmd_params)
	{
		while (cmd_params[i])
		{
			free(cmd_params[i]);
			i++;
		}
		free(cmd_params);
	}
	exit(1);
}
