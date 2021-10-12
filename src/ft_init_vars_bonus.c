/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 10:59:16 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/12 11:36:05 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

int	ft_init_vars(t_vars *vars)
{
	vars->infile = NULL;
	vars->outfile = NULL;
	vars->limiter = NULL;
	vars->commands = NULL;
	return (0);
}
