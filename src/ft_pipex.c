/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucorrei <hucorrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:27:31 by hucorrei          #+#    #+#             */
/*   Updated: 2023/01/19 13:30:29 by hucorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_child_cmd_one(int *pipefd, int *fd, char **argv, char **envp)
{
	char 	**cmd;
	pid_t	c_pid;
	
	c_pid = fork();
	if (c_pid < 0)
		ft_terminer("fork");
	if (c_pid == 0)
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			ft_terminer(argv[1]);
		cmd = ft_split(argv[2], ' ');
		close(pipefd[0]);
		dup2(fd[0], STDOUT_FILENO);
		dup2(pipefd[1], STDIN_FILENO);
		if ((cmd[0]) && ft_path(cmd[0], envp))
			execve(ft_path(cmd[0], envp), cmd, envp);
			//en theorie free ft_split mais en dessous de exec plus d'execution
		else
		{
			ft_free(cmd);
			write(2, "cmd not found", 13);
			exit(EXIT_FAILURE);
		}
		
	}
}

void	ft_child_cmd_two(int *pipefd, int *fd, char **argv, char **envp)
{
	char **cmd;
	pid_t c_pid;
	
	c_pid = fork ();
	if (c_pid < 0)
		ft_terminer("fork");
	if (c_pid == 0)
	{
		fd[1] = open(argv[4], O_WRONLY | O_CREAT, 0644);
		if (fd[1] < 0)
			ft_terminer(argv[4]);
		cmd = ft_split(argv[3], ' ');
		close(pipefd[1]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(pipefd[0], STDIN_FILENO);
		if ((cmd[0]) && ft_path(cmd[0], envp))
			execve(ft_path(cmd[0], envp), cmd, envp);
			//en theorie free ft_split mais en dessous de exec plus d'execution
		else
		{	
			ft_free(cmd);
			write(2, "cmd not found", 13);
			exit(EXIT_FAILURE);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	fd[2];
	int	status;
	
	errno = 0;
	if (argc != 5)
	{
		write(2, "error with your command, please use: ./pipex [file1] [cmd1] [cmd2] [file2]\n", 75);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd) < 0)
		ft_terminer("pipe");
	ft_child_cmd_one(pipefd, fd, argv, envp);
	ft_child_cmd_two(pipefd, fd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	wait(&status);
	wait(&status);
	return (0);
}
