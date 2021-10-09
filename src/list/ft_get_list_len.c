/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_list_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 18:44:15 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/08 18:48:11 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	ft_get_list_len(t_cmd_list *cmd_lst)
{
	int	i;

	i = 0;
	while (cmd_lst)
	{
		cmd_lst = cmd_lst->next;
		i++;
	}
	return (i);
}
