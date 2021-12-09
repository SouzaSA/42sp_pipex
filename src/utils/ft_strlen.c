/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 14:18:56 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/08 20:11:35 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_shared.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s && s[size] != '\0')
	{
		size++;
	}
	return (size);
}
