/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:01:59 by sde-alva          #+#    #+#             */
/*   Updated: 2021/10/04 11:16:05 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	*ft_strchr(const char *s, int c)
{
	char	*match;
	int		i;

	i = 0;
	match = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			match = (char *)s + i;
			break ;
		}
		i++;
	}
	if (c == '\0')
		match = (char *)s + i;
	return (match);
}
