/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 12:03:35 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/06 13:17:28 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_init_cmd(t_cmd *commamd, char *cmd_path, char **cmd_params)
{
	commamd->cmd_path = cmd_path;
	commamd->cmd_params = cmd_params;
}