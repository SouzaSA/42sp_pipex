/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:11:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/06 20:19:52 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	ft_clear_vars(t_vars *vars);

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		rtn;
	t_vars	vars;

	i = 0;
	rtn = -1;
	if (argc < 5)
	{
		ft_error_handler("Wrong parameter list", WRONG_PARAMETERS);
	}
	else
	{
		rtn = ft_load_vars(&vars, argc, argv, envp);
		rtn	= ft_load_pipes(&vars);
		if (vars.commands && rtn == 0)
			rtn = ft_pipex(&vars, vars.commands, envp);
		ft_clear_vars(&vars);
	}
	return (rtn);
}

static void	ft_clear_vars(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars)
	{
		if (vars->infile)
			free(vars->infile);
		if (vars->outfile)
			free(vars->outfile);
		if (vars->commands)
			ft_free_list(vars->commands);
		while (vars->path && vars->path[i])
		{
			free(vars->path[i]);
			vars->path[i] = NULL;
			i++;
		}
		if (vars->path)
			free(vars->path);
		vars->infile = NULL;
		vars->outfile = NULL;
		vars->commands = NULL;
		vars->path = NULL;
	}
}

static int	ft_load_vars(t_vars *vars, int argc, char **argv, char **envp)
{
	int		load_status;
	char	**path;

	load_status = 0;
	ft_init_vars(vars);
	path = ft_get_path(envp);
	vars->commands = ft_create_list(argc, argv, path);
	if (!vars.commands)
		load_status = ft_error_handler("Error on commands", WRONG_PARAMETERS);
	vars->infile = ft_strdup(argv[1]);
	vars->outfile = ft_strdup(argv[argc - 1]);
	if (!vars->infile || !vars->outfile)
		load_status = -1;
	return (load_status);
}

static int ft_load_pipes(t_vars *vars)
{
	int			load_status;
	t_cmd_list	*cmds;
	t_cmd_list	*error_cmd;

	cmds = vars->commands;
	while (cmds->next)
	{
		load_status = pipe(cmds->cmd.fd_pipe);
		if (load_status == -1)
		{
			ft_error_handler("Can't open pipes", errno);
			error_cmd = cmds;
			break ;
		}
		cmds = cmds->next;
	}
	if (load_status == -1)
	{
		cmds = vars->commands;
		while (cmds != error_cmd)
		{
			close(cmds->cmd.fd_pipe[0]);
			close(cmds->cmd.fd_pipe[1]);
			cmds = cmds->next;
		}
	}
	return (load_status);
}