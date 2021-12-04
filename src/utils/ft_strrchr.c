/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 18:50:03 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/04 11:01:57 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_shared.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*match;
	int		i;

	i = 0;
	match = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			match = (char *)s + i;
		}
		i++;
	}
	if (c == '\0')
		match = (char *)s + i;
	return (match);
}
