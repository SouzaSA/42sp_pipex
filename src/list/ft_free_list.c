/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:32:30 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 14:35:04 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_free_list(t_cmd_list *lst)
{
	t_cmd_list	*tmp;

	while (lst)
	{
		tmp = lst;
		if (lst->cmd_path)
			free(lst->cmd_path);
		lst->cmd_path = NULL;
		if (lst->cmd)
			ft_cleaner_strstr(lst->cmd);
		lst->cmd = NULL;
		lst = lst->next;
		free(tmp);
	}
}
