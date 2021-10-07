/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:32:30 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/07 12:39:48 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	*ft_free_list(t_cmd_list *lst)
{
	t_cmd_list	*tmp;

	while (lst)
	{
		tmp = lst;
		if (lst->cmd.cmd_path)
			free(lst->cmd.cmd_path);
		lst->cmd.cmd_path = NULL;
		if (lst->cmd.cmd_params)
			ft_cleaner_strstr(lst->cmd.cmd_params);
		lst->cmd.cmd_params = NULL;
		lst = lst->next;
		free(tmp);
	}
	return (NULL);
}
