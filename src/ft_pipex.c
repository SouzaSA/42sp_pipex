/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:40:04 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/17 21:47:07 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_pipex(t_vars *vars)
{
	int		rtn;

	vars->arg_idx = 2;
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
