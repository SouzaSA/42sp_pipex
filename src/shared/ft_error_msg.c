/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:35:03 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/17 20:13:29 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_shared.h"

int	ft_error_msg(char *msg)
{
	if (msg)
		ft_putendl_fd(msg, 2);
	else
		perror(NULL);
	return (1);
}
