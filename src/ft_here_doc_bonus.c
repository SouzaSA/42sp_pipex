/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:52:09 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/18 17:45:46 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

static void	ft_get_by_limiter(int *fd, char *limiter);

int	ft_here_doc(t_vars *vars)
{
	int	fd[2];
	int	pid;
	int	rtn;

	rtn = 0;
	if (pipe(fd) == -1)
		rtn = ft_error_msg(NULL);
	pid = fork();
	if (pid == -1)
		rtn = ft_error_msg(NULL);
	if (pid == 0)
		ft_get_by_limiter(fd, vars->argv[2]);
	else
	{
		waitpid(pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	return (rtn);
}

static void	ft_get_by_limiter(int *fd, char *limiter)
{
	char	*line;

	close(fd[0]);
	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(limiter, line) == -10 \
			&& ft_strlen(line) - 1 == ft_strlen(limiter))
		{
			free(line);
			close(fd[1]);
			exit(0);
		}
		if (write(fd[1], line, ft_strlen(line)) == -1)
			ft_error_msg("Can't write a line on pipe");
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(fd[1]);
	ft_error_msg("Error on delimiter entrace");
	exit(1);
}
