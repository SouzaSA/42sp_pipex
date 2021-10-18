/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:36:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/16 17:48:01 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_shared.h"

static char		*ft_strjoin_mod(char const *s1, char const *s2);
static size_t	ft_strlen_set(const char *s, const char *set);
static void		ft_push_line(int fd, char **str_buff);
static char		*ft_pop_line(char **str_buff);

char	*get_next_line(int fd)
{
	static char	*to_read = NULL;
	char		*str;

	str = NULL;
	if (BUFFER_SIZE > 0 && fd >= 0 && read(fd, str, 0) == 0)
	{
		if (to_read && !to_read[0] && ft_strchr(to_read, '\n'))
			str = ft_pop_line(&to_read);
		else
		{
			ft_push_line(fd, &to_read);
			if (to_read)
				str = ft_pop_line(&to_read);
		}
	}
	if (!str || (to_read && *to_read == '\0'))
	{
		free(to_read);
		to_read = NULL;
	}
	return (str);
}

static char	*ft_strjoin_mod(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*dst;

	i = 0;
	s1_len = ft_strlen_set(s1, "\0");
	s2_len = ft_strlen_set(s2, "\0");
	dst = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (dst)
	{
		while (i < s1_len || i < s2_len)
		{
			if (i < s1_len)
				dst[i] = s1[i];
			if (i < s2_len)
				dst[i + s1_len] = s2[i];
			i++;
		}
		dst[s1_len + s2_len] = '\0';
	}
	return (dst);
}

static size_t	ft_strlen_set(const char *s, const char *set)
{
	size_t	i;
	size_t	j;
	int		found;

	i = 0;
	if (s)
	{
		found = 0;
		while (s[i] != '\0' && !found)
		{
			j = 0;
			while (set[j] != '\0')
			{
				if (s[i] == set[j])
					found = 1;
				j++;
			}
			i++;
		}
		if (s[i] == '\n' && s[i - 1] != '\n')
			i++;
	}
	return (i);
}

static void	ft_push_line(int fd, char **str_buff)
{
	ssize_t	gotten;
	char	*tmp;
	char	*buff;

	gotten = 0;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buff)
		gotten = read(fd, buff, BUFFER_SIZE);
	if (gotten > 0)
	{
		buff[gotten] = '\0';
		while (gotten > 0 && !ft_strchr(buff, '\n'))
		{
			tmp = *str_buff;
			*str_buff = ft_strjoin_mod(*str_buff, buff);
			if (tmp)
				free(tmp);
			gotten = read(fd, buff, BUFFER_SIZE);
			buff[gotten] = '\0';
		}
		tmp = *str_buff;
		*str_buff = ft_strjoin_mod(*str_buff, buff);
		free(tmp);
	}
	free(buff);
}

static char	*ft_pop_line(char **str_buff)
{
	size_t	i;
	size_t	line_len;
	char	*str;
	char	*tmp;

	i = 0;
	str = NULL;
	if (*str_buff && (*str_buff)[0] != '\0')
	{
		line_len = ft_strlen_set(*str_buff, "\n");
		str = (char *)malloc((line_len + 1) * sizeof(char));
		while (i < line_len)
		{
			str[i] = (*str_buff)[i];
			i++;
		}
		str[line_len] = '\0';
		tmp = *str_buff;
		*str_buff = ft_strjoin_mod(*str_buff + line_len, "");
		free(tmp);
	}
	return (str);
}
