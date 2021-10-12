/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:46:43 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/12 11:34:34 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_shared.h"

/* ************************************************************************** */
/* Responsible for error handling of program.                                 */
/* ************************************************************************** */
int	ft_error_handler(char *msg, int errnum)
{
	if (errnum == WRONG_PARAMETERS)
		ft_print_error(msg);
	else
	{
		errno = errnum;
		perror(msg);
	}
	return (-1);
}
