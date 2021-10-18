/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:11:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/17 21:19:16 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;
	int		rtn;

	vars.argc = argc;
	vars.argv = argv;
	vars.envp = envp;
	rtn = 0;
	if (argc < 5 || (ft_strcmp(argv[1], "here_doc") == 0 && argc < 6))
	{
		rtn = ft_error_msg("Wrong num of parameters");
	}
	else
	{
		rtn = ft_pipex(&vars);
	}
	return (rtn);
}
