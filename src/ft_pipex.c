/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:40:04 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/12 15:52:04 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_pipex(t_vars *vars, t_cmd_list *cmds, char **envp)
{
	int			rtn;
	int			fd_in;
	int			fd_out;
	t_cmd_list	*last_cmd;

	rtn = 0;
	last_cmd = ft_get_last_cmd(vars->commands);
	fd_in = open(vars->infile, O_RDONLY);
	if (fd_in < 0)
	{
		rtn = ft_error_handler(vars->infile, errno);
	}
	else if (rtn >= 0)
	{
		fd_out = open(vars->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		dup2(fd_in, 0);
		while (cmds)
		{
			rtn = ft_forker(cmds, envp, fd_out);
			cmds = cmds->next;
		}
	}
	return (rtn);
}
