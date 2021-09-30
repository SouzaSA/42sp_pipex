/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftpipex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:01:42 by sde-alva          #+#    #+#             */
/*   Updated: 2021/09/29 19:10:37 by sde-alva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPIPEX_H
# define LIBFTPIPEX_H
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* ************************************************************************** */
/* Macros */
/* ************************************************************************** */
# define WRONG_PARAMETERS 2000


int		ft_error_handler(char *msg, int errnum);
int		ft_print_help(char *msg);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
#endif