/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:40:04 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/12 18:28:44 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

static int	ft_open_files(t_vars *vars, int *fd_in, int *fd_out);
static int	ft_here_doc(t_vars *vars);
static int	ft_get_by_limiter(int *fd, t_vars *vars);
static void	ft_clear_exit(t_vars *vars);

int	ft_pipex(t_vars *vars, t_cmd_list *cmds, char **envp)
{
	int			fd_in;
	int			fd_out;
	int			rtn;
	t_cmd_list	*last_cmd;

	last_cmd = ft_get_last_cmd(vars->commands);
	rtn = ft_open_files(vars, &fd_in, &fd_out);
	while (rtn >= 0 && cmds)
	{
		ft_forker(cmds, envp, fd_out);
		cmds = cmds->next;
	}
	if (ft_strcmp(vars->infile, "here_doc") != 0)
		close(fd_in);
	close(fd_out);
	return (0);
}

static int	ft_open_files(t_vars *vars, int *fd_in, int *fd_out)
{
	int	rtn;

	rtn = 0;
	if (ft_strcmp(vars->infile, "here_doc") == 0)
	{
		ft_here_doc(vars);
		*fd_out = open(vars->outfile, O_CREAT | O_WRONLY | O_APPEND, 0777);
	}
	else
	{
		*fd_in = open(vars->infile, O_RDONLY);
		if (*fd_in > 0)
		{
			dup2(*fd_in, 0);
			*fd_out = open(vars->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		}
		else
		{
			rtn = ft_error_handler(vars->infile, errno);
		}
	}
	return (rtn);
}

static int	ft_here_doc(t_vars *vars)
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
	if (pid == 0)
		ft_get_by_limiter(fd, vars);
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	return (rtn);
}

static int	ft_get_by_limiter(int *fd, t_vars *vars)
{
	int		rtn;
	char	*line;

	rtn = 0;
	close(fd[0]);
	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(vars->limiter, line) == -10)
		{
			free(line);
			close(fd[1]);
			ft_clear_exit(vars);
		}
		if (write(fd[1], line, ft_strlen(line)) == -1)
			rtn = ft_error_handler("Can't write a line on pipe", errno);
		if (write(fd[1], "\n", 1) == -1)
			rtn = ft_error_handler("Can't write a new line on pipe", errno);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(fd[1]);
	rtn = ft_error_handler("Error on delimiter entrace", errno);
	exit(rtn);
}

static void	ft_clear_exit(t_vars *vars)
{
	if (vars)
	{
		if (vars->infile)
			free(vars->infile);
		if (vars->outfile)
			free(vars->outfile);
		if (vars->limiter)
			free(vars->limiter);
		if (vars->commands)
			ft_free_list(vars->commands);
	}
	exit(0);
}
