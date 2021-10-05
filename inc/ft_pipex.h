/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:01:42 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 17:06:03 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_cmd_list
{
	char				*cmd_path;
	char				**cmd;
	struct s_cmd_list	*next;
}	t_cmd_list;

typedef struct s_vars
{
	char		*infile;
	char		*outfile;
	char		**path;
	t_cmd_list	*commands;
}	t_vars;

/* ************************************************************************** */
/* Macros */
/* ************************************************************************** */
# define WRONG_PARAMETERS 2000

t_cmd_list	*ft_create_list(int argc, char **argv, char **path);
void		ft_free_list(t_cmd_list *lst);
t_cmd_list	ft_get_last_cmd(t_cmd_list *cmd_list);
t_cmd_list	*ft_new_node(char *command, char **path_list);

int			ft_checker_slash(char *str);
void		ft_cleaner_strstr(char **str);
int			ft_error_handler(char *msg, int errnum);
char		**ft_get_path(char **envp);
int			ft_init_vars(t_vars *vars);
int			ft_pipex(t_vars *vars, char **envp);
int			ft_print_error(char *msg);

void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_putendl_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
#endif