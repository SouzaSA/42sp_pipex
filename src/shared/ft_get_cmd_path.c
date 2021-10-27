/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 11:24:35 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/27 09:32:56 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_shared.h"

static char	*ft_join_cmd_path(char *command, char **path_list);

char	*ft_get_cmd_path(char *command, char **path_list)
{
	char	*path_cmd;

	path_cmd = NULL;
	if (ft_checker_slash(command) && access(command, X_OK) == 0)
		path_cmd = ft_strdup(command);
	else
		path_cmd = ft_join_cmd_path(command, path_list);
	return (path_cmd);
}

static char	*ft_join_cmd_path(char *command, char **path_list)
{
	int		i;
	char	*path_cmd;
	char	*cmd_slashed;
	char	*returm_msg;

	i = 0;
	path_cmd = NULL;
	cmd_slashed = ft_strjoin("/", command);
	while (path_list[i])
	{
		path_cmd = ft_strjoin(path_list[i], cmd_slashed);
		if (access(path_cmd, X_OK) == 0)
			break ;
		free (path_cmd);
		path_cmd = NULL;
		i++;
	}
	free(cmd_slashed);
	if (!path_cmd)
	{
		returm_msg = ft_strjoin("command not found: ", command);
		ft_error_msg(returm_msg);
		free(returm_msg);
	}
	return (path_cmd);
}
