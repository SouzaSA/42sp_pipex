/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:50:30 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 12:35:48 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static char	*ft_check_path(char *command, char **path_list);

t_cmd_list	*ft_new_node(char *command, char **path_list)
{
	t_cmd_list	*node;

	node = (t_cmd_list *)malloc(sizeof(t_cmd_list));
	node->cmd = ft_split(command, ' ');
	node->cmd_path = ft_check_path(node->cmd[0], path_list);
	if (!node->cmd_path)
	{
		ft_cleaner_strstr(node->cmd);
		node->cmd = NULL;
		free(node);
		node = NULL;
	}
	else
	{
		node->next = NULL;
	}
	return (node);
}

static char	*ft_check_path(char *command, char **path_list)
{
	int		i;
	int		is_exec;
	char	*path_cmd;
	char	*cmd_slashed;

	i = 0;
	path_cmd = NULL;
	cmd_slashed = ft_strjoin("/", command);
	while (path_list[i])
	{
		path_cmd = ft_strjoin(path_list[i], cmd_slashed);
		is_exec = access(path_cmd, X_OK);
		if (is_exec == 0)
			break ;
		free (path_cmd);
		path_cmd = NULL;
		i++;
	}
	free(cmd_slashed);
	return (path_cmd);
}
