/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:26:26 by dams              #+#    #+#             */
/*   Updated: 2023/09/19 21:26:14 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include <stdarg.h>
# include <stddef.h>
# include <string.h>
# include <limits.h>
# include <sys/wait.h>

/*	utils.c	*/
char	*path_cmd(char **path, char *cmd);
void	ft_error(char *str);
/*	pipex.c	*/
int		parent_process(int *fd, char **argv, char **env);
int		child_process(int *fd, char **argv, char **env);
/*	libft/	*/
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);

#endif
