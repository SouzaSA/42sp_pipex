/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 10:59:16 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 11:17:41 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_init_vars(t_vars *vars)
{
	vars->infile = NULL;
	vars->outfile = NULL;
	vars->path = NULL;
	vars->commands = NULL;
	return (0);
}
