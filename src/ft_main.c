/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 10:55:50 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/06 14:51:24 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	ft_clear_vars(t_vars *vars);

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**path;
	t_vars	vars;

	i = 0;
	if (argc != 5)
	{
		ft_error_handler("Wrong parameter list", WRONG_PARAMETERS);
	}
	else
	{
		ft_init_vars(&vars);
		path = ft_get_path(envp);
		vars.commands = ft_create_list(argc, argv, path);
		if (!vars.commands)
			ft_error_handler("Error on commands", WRONG_PARAMETERS);
		vars.infile = ft_strdup(argv[1]);
		vars.outfile = ft_strdup(argv[argc - 1]);
		if (vars.commands)
			ft_pipex(&vars, envp);
		ft_clear_vars(&vars);
	}
	return (0);
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
