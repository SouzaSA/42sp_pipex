/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 11:45:00 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 11:17:33 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/* ************************************************************************** */
/* Responsible get the environment PATH, and split it into a array of paths.  */
/* ************************************************************************** */
char	**ft_get_path(char **envp)
{
	int		i;
	char	*str;
	char	**path;

	i = 0;
	str = NULL;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			str = ft_strdup(envp[i] + 5);
		i++;
	}
	if (str)
	{
		path = ft_split(str, ':');
		free(str);
	}
	return (path);
}
