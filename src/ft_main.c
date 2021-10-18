/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 10:55:50 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/16 21:11:36 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	int		rtn;

	vars.argc = argc;
	vars.argv = argv;
	vars.envp = envp;
	rtn = 0;
	if (argc != 5)
	{
		rtn = ft_error_msg("Wrong num of parameters");
	}
	else
	{
		rtn = ft_pipex(&vars);
	}
	return (rtn);
}
