/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dams <dams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 00:06:11 by dams              #+#    #+#             */
/*   Updated: 2023/09/15 00:52:42 by dams             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path(char **env)
{
	int		i;
	char	**path;
	char	*env_path;

	if (!env)
		return (NULL);
	env_path = NULL;
	i = 0;
	while (env[i++])
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			env_path = strdup(env[i]);
			break ;
		}
	}
	path = ft_split(env_path, ':');
	if (env_path)
		free(env_path);
	return (path);
}

static char	**add_slash(char **path)
{
	int	i;

	i = 0;
	path = get_path(path);
	while (path[i++])
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
	if (!cmd)
		return (NULL);
	while (cmd[i++])
	{
		if (cmd[i] == '/')
		{
			if (access(cmd, F_OK | X_OK) == 0)
				return (cmd);
			return (NULL);
		}
	}
	path = add_slash(path);
	i = 0;
	while (path[i++])
	{
		cmd_path = ft_strjoin(path[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free (cmd_path);
	}
	return (NULL);
}
