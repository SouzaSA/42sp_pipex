/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:46:43 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/29 13:54:54 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpipex.h"

int	ft_error_handler(char *msg, int errnum)
{
	if (errnum == WRONG_PARAMETERS)
		ft_print_help(msg);
	else
	{
		errno = errnum;
		perror(msg);
	}
	return (-1);
}
