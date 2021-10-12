/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:11:39 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/12 11:33:51 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_shared.h"

static int	ft_get_first_cmd_pos(char **argv);

t_cmd_list	*ft_create_list(int argc, char **argv, char **path)
{
	int			i;
	int			is_success;
	t_cmd_list	*cmds;
	t_cmd_list	*rtn_list;

	i = ft_get_first_cmd_pos(argv);
	is_success = 1;
	cmds = ft_new_node(argv[i - 1], path);
	rtn_list = cmds;
	if (!cmds)
		is_success = 0;
	while (i < argc - 1 && is_success)
	{
		cmds->next = ft_new_node(argv[i], path);
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

static int	ft_get_first_cmd_pos(char **argv)
{
	int	idx;

	idx = 3;
	if (ft_strcmp((const char *)argv[1], "here_doc") == 0)
		idx = 4;
	return (idx);
}
