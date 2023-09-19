/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 00:06:11 by dams              #+#    #+#             */
/*   Updated: 2023/09/19 19:21:48 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(errno);
}

static char	**get_path(char **env)
{
	int		i;
	char	**path;

	i = -1;
	while (env[++i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			if (ft_strlen(env[i]) < 6)
				ft_error("Path is empty");
			path = ft_split(&env[i][5], ':');
			if (!path)
				ft_error("failed try again");
			return (path);
		}
	}
	ft_error("Error get path");
	return (NULL);
}

static char	**add_slash(char **path)
{
	int	i;

	i = -1;
	path = get_path(path);
	if (!path)
		ft_error("error path");
	while (path[++i])
	{
		path[i] = ft_strjoin(path[i], "/");
	}
	return (path);
}

char	*path_cmd(char **path, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = 0;
	cmd_path = NULL;
	path = add_slash(path);
	while (path[i])
	{
		cmd_path = ft_strjoin(path[i], cmd);
		if (!cmd_path)
			ft_error("Malloc failed");
		if (access(cmd_path, F_OK) == 0)
		{
			return (cmd_path);
		}
		i++;
	}
	ft_error("Command not found");
	return (0);
}
