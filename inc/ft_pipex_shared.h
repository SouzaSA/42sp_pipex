/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_shared.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:01:42 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/12 18:08:05 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_SHARED_H
# define FT_PIPEX_SHARED_H
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define WRONG_PARAMETERS 2000

typedef struct s_cmd
{
	char	*cmd_path;
	char	**cmd_params;
}	t_cmd;

typedef struct s_cmd_list
{
	t_cmd				cmd;
	struct s_cmd_list	*next;
}	t_cmd_list;

t_cmd_list	*ft_create_list(int argc, char **argv, char **path);
void		*ft_free_list(t_cmd_list *lst);
t_cmd_list	*ft_get_last_cmd(t_cmd_list *cmd_list);
void		ft_init_cmd(t_cmd *cmd, char *path, char **params);
t_cmd_list	*ft_new_node(char *cmd, char **path_list);

int			ft_checker_slash(char *str);
void		ft_cleaner_strstr(char **str);
int			ft_error_handler(char *msg, int errnum);
int			ft_forker(t_cmd_list *cmds, char **envp, int fd_out);
char		**ft_get_path(char **envp);
int			ft_print_error(char *msg);

void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char c);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin_mod(char const *s1, char const *s2);
size_t		ft_strlen_set(const char *s, const char *set);
void		ft_push_line(int fd, char **str_buff);
char		*ft_pop_line(char **str_buff);
#endif
