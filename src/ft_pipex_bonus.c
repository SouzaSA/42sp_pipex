/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:40:04 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/17 21:49:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

int	ft_pipex(t_vars *vars)
{
	int	rtn;

	rtn = 0;
	vars->arg_idx = 2;
	if (ft_strcmp(vars->argv[1], "here_doc") == 0)
	{
		vars->arg_idx = 3;
		ft_here_doc(vars);
	}
	vars->env_path = ft_get_path(vars->envp);
	while (vars->arg_idx < vars->argc - 1)
	{
		rtn = ft_forker(vars);
		vars->arg_idx++;
	}
	ft_cleaner_strstr(vars->env_path);
	vars->env_path = NULL;
	return (rtn);
}
