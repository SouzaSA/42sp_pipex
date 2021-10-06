/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:11:39 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/06 14:49:18 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static char	**ft_get_path(char **envp);

t_cmd_list	*ft_create_list(int argc, char **argv, char **env_path)
{
	int			i;
	int			is_success;
	t_cmd_list	*cmd;
	t_cmd_list	*rtn_list;

	i = 3;
	is_success = 1;
	cmd = ft_new_node(argv[2], env_path);
	rtn_list = cmd;
	if (!cmd)
		is_success = 0;
	while (i < argc - 1 && is_success)
	{
		cmd->next = ft_new_node(argv[i], env_path);
		if (!cmd->next)
		{
			is_success = 0;
			break ;
		}
		cmd = cmd->next;
		i++;
	}
	if (!is_success)
		rtn_list = ft_free_list(rtn_list);
	return (rtn_list);
}
