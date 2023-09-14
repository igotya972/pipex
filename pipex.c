/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dams <dams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:26:13 by dams              #+#    #+#             */
/*   Updated: 2023/09/15 01:20:27 by dams             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(int *fd, char **argv, char **env)
{
	
}

int	parent_process(int *fd, char **argv, char **env)
{

}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid;
	int		fd[2];

		//ft_error_bis();
	if (argc != 5)
		exit(EXIT_FAILURE);
	else if (pipe(fd) == -1)
	{
		perror("pipe failed\n");
		return (1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed\n");
		return (2);
	}
	//else if (pid == 0)
	//	child_process(fd, argv, env);
	//else
	//	parent_process(fd, argv, env);
	//waitpid(-1, NULL, 0);
	//waitpid(-1, NULL, 0);
	return (0);
}
