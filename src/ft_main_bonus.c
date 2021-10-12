/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:11:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/12 18:31:08 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

static void	ft_clear_vars(t_vars *vars);
static int	ft_load_vars(t_vars *vars, int argc, char **argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		rtn;
	t_vars	vars;

	i = 0;
	rtn = 0;
	if (argc < 5 || (ft_strcmp(argv[1], "here_doc") == 0 && argc < 6))
	{
		rtn = ft_error_handler("Wrong parameter list", WRONG_PARAMETERS);
	}
	else
	{
		rtn = ft_load_vars(&vars, argc, argv, envp);
		if (vars.commands && rtn == 0)
			rtn = ft_pipex(&vars, vars.commands, envp);
		ft_clear_vars(&vars);
	}
	return (rtn);
}

static void	ft_clear_vars(t_vars *vars)
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
		vars->infile = NULL;
		vars->outfile = NULL;
		vars->limiter = NULL;
		vars->commands = NULL;
	}
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
	if (ft_strcmp(argv[1], "here_doc") == 0)
		vars->limiter = ft_strdup(argv[2]);
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
