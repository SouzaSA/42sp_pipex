/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:54:13 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 12:03:33 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/* ************************************************************************** */
/* Responsible for put a help mesg in terminal.                               */
/* ************************************************************************** */
int	ft_print_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	ft_putendl_fd("Example of use:", 2);
	ft_putendl_fd("  ./pipex file1 cmd1 cmd2 file2", 2);
	return (0);
}