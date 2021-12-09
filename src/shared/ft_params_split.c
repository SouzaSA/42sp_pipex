/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 08:33:22 by sde-alva          #+#    #+#             */
/*   Updated: 2021/12/08 20:34:20 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_shared.h"

static char	**ft_get_param_addresses(char *params, char c);
static int	ft_params_cnt(char *params, char c);

char	**ft_params_split(char const *params, char c)
{
	int		i;
	int		num_params;
	char	*params_copy;
	char	**params_addresses;
	char	**params_splited;

	i = 0;
	params_copy = ft_strdup(params);
	num_params = ft_params_cnt(params_copy, c);
	params_addresses = ft_get_param_addresses(params_copy, c);
	params_splited = (char **)malloc((num_params + 1) * sizeof(char *));
	while (i < num_params)
	{
		params_splited[i] = ft_strdup(params_addresses[i]);
		i++;
	}
	params_splited[i] = NULL;
	free(params_copy);
	free(params_addresses);
	return (params_splited);
}

static char	**ft_get_param_addresses(char *params, char c)
{
	int		i;
	int		j;
	int		not_cnt;
	char	**addrs;

	i = 0;
	j = 0;
	not_cnt = 0;
	addrs = (char **)malloc((ft_params_cnt(params, c) + 1) * sizeof(char *));
	while (params[i])
	{
		if (!not_cnt && params[i] != c && (i == 0 || params[i - 1] == c))
		{
			addrs[j] = &params[i];
			if (i != 0)
				params[i - 1] = '\0';
			j++;
		}
		if (params[i] == '\'')
			not_cnt = !not_cnt;
		i++;
	}
	addrs[j] = NULL;
	return (addrs);
}

static int	ft_params_cnt(char *params, char c)
{
	int	i;
	int	not_cnt;
	int	num_params;

	i = 0;
	not_cnt = 0;
	num_params = 0;
	while (params[i])
	{
		if (!not_cnt && params[i] != c && (i == 0 || params[i - 1] == c))
			num_params++;
		if (params[i] == '\'')
			not_cnt = !not_cnt;
		i++;
	}
	return (num_params);
}
