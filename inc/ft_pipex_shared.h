/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_shared.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:01:42 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/27 09:22:57 by sde-alva         ###   ########.fr       */
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
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_vars
{
	int		arg_idx;
	int		argc;
	char	**argv;
	char	**envp;
	char	**env_path;
}	t_vars;

int		ft_checker_slash(char *str);
void	ft_cleaner_strstr(char **str);
int		ft_error_msg(char *msg);
char	*ft_get_cmd_path(char *command, char **path_list);
char	**ft_get_path(char **envp);

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
