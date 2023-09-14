/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dams <dams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:26:26 by dams              #+#    #+#             */
/*   Updated: 2023/09/15 00:49:46 by dams             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "printf/libftprintf.h"

/*  Pipex/pipex.c  */
typedef enum	e_bool
{
	false,
	true
}				t_bool;
 
typedef struct	s_pipex
{
	int		*in_fd;
	int		*out_fd;
	int		cmd_count;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	t_bool	here_doc; // use `int` if you prefer
	t_bool	is_invalid_infile;
}				t_pipex;

char	*path_cmd(char **path, char *cmd);
int		parent_process(int *fd, char **argv, char **env);
int		child_process(int *fd, char **argv, char **env);

/*	libft	*/
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);