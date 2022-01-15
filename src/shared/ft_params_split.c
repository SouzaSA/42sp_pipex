/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 08:33:22 by sde-alva          #+#    #+#             */
/*   Updated: 2022/01/15 17:23:27 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_shared.h"

static char	**ft_get_param_addresses(char *str, char c);
static void	ft_params_addr_set(char *str, char c, char **addrs);
static int	ft_params_cnt(char *str, char c);

char	**ft_params_split(char const *str, char c)
{
	int		i;
	int		num_params;
	char	*params_copy;
	char	**params_addresses;
	char	**params_splited;

	i = 0;
	params_copy = ft_strdup(str);
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

static char	**ft_get_param_addresses(char *str, char c)
{
	char	**addrs;

	addrs = (char **)malloc((ft_params_cnt(str, c) + 1) * sizeof(char *));
	if (addrs)
		ft_params_addr_set(str, c, addrs);
	return (addrs);
}

static void	ft_params_addr_set(char *str, char c, char **addrs)
{
	int		i;
	int		j;
	int		not_cnt;

	i = 0;
	j = 0;
	not_cnt = 0;
	while (str[i])
	{
		if (!not_cnt && str[i] != c && (i == 0 || str[i - 1] == '\0'))
		{
			addrs[j] = &str[i];
			if (str[i] == '\'')
				addrs[j] = &str[i + 1];
			j++;
		}
		if (str[i] == '\'')
			not_cnt = !not_cnt;
		if (str[i] == '\'' || (!not_cnt && str[i] == c))
			str[i] = '\0';
		i++;
	}
	addrs[j] = NULL;
}

static int	ft_params_cnt(char *str, char c)
{
	int	i;
	int	not_cnt;
	int	num_params;

	i = 0;
	not_cnt = 0;
	num_params = 0;
	while (str[i])
	{
		if (!not_cnt && str[i] != c && (i == 0 || str[i - 1] == c))
			num_params++;
		if (str[i] == '\'')
			not_cnt = !not_cnt;
		i++;
	}
	return (num_params);
}
