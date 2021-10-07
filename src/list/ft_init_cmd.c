/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:03:35 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/07 16:22:54 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_init_cmd(t_cmd *cmd, char *path, char **params, int *ant_pipe)
{
	cmd->anterior_pipe = ant_pipe;
	cmd->cmd_path = path;
	cmd->cmd_params = params;
}
