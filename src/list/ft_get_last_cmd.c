/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:01:41 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 17:05:19 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

t_cmd_list	ft_get_last_cmd(t_cmd_list *cmd_list)
{
	t_cmd_list	*tmp;

	tmp = cmd_list;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}
