/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:11:39 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/07 16:41:37 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

t_cmd_list	*ft_create_list(int argc, char **argv, char **path)
{
	int			i;
	int			is_success;
	t_cmd_list	*cmds;
	t_cmd_list	*rtn_list;

	i = 3;
	is_success = 1;
	cmds = ft_new_node(argv[2], path, NULL);
	rtn_list = cmds;
	if (!cmds)
		is_success = 0;
	while (i < argc - 1 && is_success)
	{
		cmds->next = ft_new_node(argv[i], path, cmds->cmd.fd_pipe);
		if (!cmds->next)
		{
			is_success = 0;
			break ;
		}
		cmds = cmds->next;
		i++;
	}
	if (!is_success)
		rtn_list = ft_free_list(rtn_list);
	return (rtn_list);
}
