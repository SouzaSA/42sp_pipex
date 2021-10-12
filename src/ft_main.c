/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 10:55:50 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/12 13:06:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static int	ft_load_vars(t_vars *vars, int argc, char **argv, char **envp);
static void	ft_clear_vars(t_vars *vars);

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		rtn;
	t_vars	vars;

	i = 0;
	rtn = 0;
	if (argc != 5)
	{
		ft_error_handler("Wrong parameter list", WRONG_PARAMETERS);
	}
	else
	{
		rtn = ft_load_vars(&vars, argc, argv, envp);
		if (vars.commands && rtn == 0)
			ft_pipex(&vars, vars.commands, envp);
		ft_clear_vars(&vars);
	}
	return (rtn);
}

static int	ft_load_vars(t_vars *vars, int argc, char **argv, char **envp)
{
	int		i;
	int		load_status;
	char	**path;

	i = 0;
	load_status = 0;
	ft_init_vars(vars);
	path = ft_get_path(envp);
	vars->commands = ft_create_list(argc, argv, path);
	if (!vars->commands)
		load_status = ft_error_handler("Error on commands", WRONG_PARAMETERS);
	vars->infile = ft_strdup(argv[1]);
	vars->outfile = ft_strdup(argv[argc - 1]);
	if (!vars->infile || !vars->outfile)
		load_status = -1;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
	return (load_status);
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
		vars->infile = NULL;
		vars->outfile = NULL;
		vars->commands = NULL;
	}
}
