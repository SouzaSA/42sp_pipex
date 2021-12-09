/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forker_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:04:37 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/08 21:16:05 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

static void	ft_child(t_vars *vars, int *fd_pipe);
static void	ft_parent(t_vars *vars, int *fd_pipe, int pid);
static int	ft_openfile(t_vars *vars, char *name, int open_type);
static void	ft_cleaner_exit(t_vars *vars, char *cmd_path, char **cmd_params);

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
		fd_in = ft_openfile(vars, vars->argv[1], 1);
		dup2(fd_in, 0);
		close(fd_in);
	}
	cmd_params = ft_params_split(vars->argv[vars->arg_idx], ' ');
	cmd_path = ft_get_cmd_path(cmd_params[0], vars->env_path);
	dup2(fd_pipe[1], 1);
	close(fd_pipe[1]);
	if (cmd_path)
	{
		execve(cmd_path, cmd_params, vars->envp);
		ft_error_msg(NULL);
	}
	ft_cleaner_exit(vars, cmd_path, cmd_params);
}

static void	ft_parent(t_vars *vars, int *fd_pipe, int pid)
{
	int		fd_out;
	char	*cmd_path;
	char	**cmd_params;

	close(fd_pipe[1]);
	if (vars->arg_idx == vars->argc - 2)
	{
		waitpid(pid, NULL, 0);
		fd_out = ft_openfile(vars, vars->argv[vars->argc - 1], 0);
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

static int	ft_openfile(t_vars *vars, char *name, int open_type)
{
	int	fd_file;

	if (open_type == 0)
	{
		if (ft_strcmp(vars->argv[1], "here_doc") == 0)
			fd_file = open(name, O_CREAT | O_WRONLY | O_APPEND, 0666);
		else
			fd_file = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	}
	if (open_type == 1)
	{
		fd_file = open(name, O_RDONLY);
	}
	if (fd_file < 0)
	{
		ft_error_msg(NULL);
		ft_cleaner_exit(vars, NULL, NULL);
	}
	return (fd_file);
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
