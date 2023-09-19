/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dams <dams@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:26:13 by dams              #+#    #+#             */
/*   Updated: 2023/09/19 18:24:43 by dams             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(int *fd, char **argv, char **env)
{
	int		fd_inf;
	char	*path;
	char	**arg;

	fd_inf = open(argv[1], O_RDONLY);
	if (fd_inf < 0)
		perror(argv[1]);
	if (access(argv[1], F_OK) != 0)
		ft_error("No such file or directory error\n");
	if (access(argv[1], R_OK) != 0)
		ft_error("Permission denied error\n");
	(void) fd;
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(fd_inf, STDIN_FILENO);
	close(fd_inf);
	arg = ft_split(argv[2], ' ');
	path = path_cmd(env, arg[0]);
	execve(path, arg, env);
	ft_error("Exec failed");
	return (0);
}

int	parent_process(int *fd, char **argv, char **env)
{
	int		fd_out;
	char	*path;
	char	**arg;

	fd_out = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_out < 0)
		perror(argv[4]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	arg = ft_split(argv[3], ' ');
	path = path_cmd(env, arg[0]);
	execve(path, arg, env);
	ft_error("Exec failed");
	return (0);
}

int	main(int ac, char **av, char *envp[])
{
	int	pid;
	int	fd[2];

	if (ac == 5)
	{
		if (pipe(fd) == -1)
			ft_error("Fails pipe");
		pid = fork();
		if (pid < 0)
			ft_error("Fail fork");
		if (pid == 0)
			child_process(fd, av, envp);
		waitpid(pid, NULL, 0);
		close(fd[1]);
		parent_process(fd, av, envp);
	}
	else
		ft_error("ARGS != 5");
	exit(EXIT_FAILURE);
}
