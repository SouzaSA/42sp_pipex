/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_slash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:32:20 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/08 20:08:28 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_shared.h"

/* ************************************************************************** */
/* Responsible for check if the user are passing a path to a command.         */
/* ************************************************************************** */
int	ft_checker_slash(char *str)
{
	int	has_slash;

	has_slash = 0;
	if (str)
	{
		if ((ft_strlen(str) > 0 && ft_strncmp(str, "/", 1) == 0) \
			|| (ft_strlen(str) > 1 && ft_strncmp(str, "./", 2) == 0) \
			|| (ft_strlen(str) > 2 && ft_strncmp(str, "../", 3) == 0))
			has_slash = 1;
	}
	return (has_slash);
}
