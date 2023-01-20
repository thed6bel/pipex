/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:27:31 by hucorrei          #+#    #+#             */
/*   Updated: 2023/01/20 14:05:42 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static pid_t	ft_child_cmd_one(int *pipefd, int *fd, char **argv, char **envp)
{
	char	**cmd;
	pid_t	c_pid;

	cmd = ft_split(argv[2], ' ');
	c_pid = fork();
	if (c_pid < 0)
		ft_exit("fork");
	if (c_pid == 0)
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			ft_exit(argv[1]);
		close(pipefd[0]);
		dup2(fd[0], STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close(fd[0]);
		close(pipefd[1]);
		if ((cmd[0]) && ft_path(cmd[0], envp))
			execve(ft_path(cmd[0], envp), cmd, envp);
		else
			ft_cmd_not_found(cmd);
	}
	ft_free(cmd);
	return (c_pid);
}

static pid_t	ft_child_cmd_two(int *pipefd, int *fd, char **argv, char **envp)
{
	char	**cmd;
	pid_t	c_pid;

	cmd = ft_split(argv[3], ' ');
	c_pid = fork ();
	if (c_pid < 0)
		ft_exit("fork");
	if (c_pid == 0)
	{
		fd[1] = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd[1] < 0)
			ft_exit(argv[4]);
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		close(fd[1]);
		close(pipefd[0]);
		if ((cmd[0]) && ft_path(cmd[0], envp))
			execve(ft_path(cmd[0], envp), cmd, envp);
		else
			ft_cmd_not_found(cmd);
	}
	ft_free(cmd);
	return (c_pid);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		fd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	errno = 0;
	if (argc != 5)
		ft_argc_error();
	if (pipe(pipefd) < 0)
		ft_exit("pipe");
	pid1 = ft_child_cmd_one(pipefd, fd, argv, envp);
	pid2 = ft_child_cmd_two(pipefd, fd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status) != 0)
		return (WEXITSTATUS(status));
	return (status);
}
