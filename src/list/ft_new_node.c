/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:50:30 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/06 13:58:35 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static char	*ft_check_path(char *command, char **path_list);

t_cmd_list	*ft_new_node(char *command, char **path_list)
{
	char		**cmd_params;
	char		*cmd_path;
	t_cmd_list	*node;

	node = (t_cmd_list *)malloc(sizeof(t_cmd_list));
	cmd_params = ft_split(command, ' ');
	cmd_path = ft_check_path(cmd_params[0], path_list);
	if (!cmd_path)
	{
		ft_cleaner_strstr(cmd_params);
		cmd_params = NULL;
		free(node);
		node = NULL;
	}
	else
	{
		ft_init_cmd(&node->cmd, cmd_path, cmd_params)
		node->next = NULL;
	}
	return (node);
}

static char	*ft_check_path(char *command, char **path_list)
{
	int		i;
	char	*path_cmd;
	char	*cmd_slashed;

	i = 0;
	path_cmd = NULL;
	if (ft_checker_slash(command) && access(command, X_OK) == 0)
	{
		path_cmd = ft_strdup(command);
	}
	else
	{
		cmd_slashed = ft_strjoin("/", command);
		while (path_list[i])
		{
			path_cmd = ft_strjoin(path_list[i], cmd_slashed);
			if (access(command, X_OK) == 0)
				break ;
			free (path_cmd);
			path_cmd = NULL;
			i++;
		}
		free(cmd_slashed);
	}
	return (path_cmd);
}
