/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:40:04 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/29 19:12:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftpipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		aux;
	int		i;
	char	**path;

	i = 0;
	if (argc < 2)
		ft_error_handler("Wrong parameter list", WRONG_PARAMETERS);
	while (envp[i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		path = ft_split(envp[i], ':');
		i++;
	}
	aux = execve(argv[1], argv, path);
	//if (aux == -1)
	//	ft_error_handler("faio", errno);
	return (0);
}
