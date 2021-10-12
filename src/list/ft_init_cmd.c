/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:03:35 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/12 11:34:09 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_shared.h"

void	ft_init_cmd(t_cmd *cmd, char *path, char **params)
{
	cmd->cmd_path = path;
	cmd->cmd_params = params;
}
