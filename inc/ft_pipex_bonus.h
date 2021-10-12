/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:01:42 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/12 11:37:17 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_BONUS_H
# define FT_PIPEX_BONUS_H
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "ft_pipex_shared.h"

# define WRONG_PARAMETERS 2000

typedef struct s_vars
{
	char		*infile;
	char		*outfile;
	char		*limiter;
	t_cmd_list	*commands;
}	t_vars;

int			ft_init_vars(t_vars *vars);
int			ft_pipex(t_vars *vars, t_cmd_list *cmds, char **envp);
#endif
