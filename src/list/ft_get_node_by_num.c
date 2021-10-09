/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_node_by_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:49:19 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/08 19:02:36 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

t_cmd_list *ft_get_node_by_num(t_cmd_list *cmd_lst, int pos)
{
	int 		i;
	t_cmd_list *node;

	i = 1;
	node = NULL;
	while (cmd_lst)
	{
		if (i == pos)
			node = cmd_lst;
		cmd_lst = cmd_lst->next;
		i++;
	}
	return (node);
}
