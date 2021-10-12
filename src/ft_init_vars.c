/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 10:59:16 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/12 11:15:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_init_vars(t_vars *vars)
{
	vars->infile = NULL;
	vars->outfile = NULL;
	vars->commands = NULL;
	return (0);
}
