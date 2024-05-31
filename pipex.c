/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:45:14 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/31 14:52:49 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_middlejob(t_cmd **lst, int fd_in, char **env, int *new_pipe)
{
	pid_t	pid;
	int		e_flg;

	e_flg = 0;
	pid = fork();
	if (pid > 0)
		wait(NULL);
	else if (pid == 0)
	{
		if (dup2(fd_in, 0) < 0 || dup2(new_pipe[1], 1) < 0)
			write_error();
		e_flg = execve((*lst)-> path, (*lst)-> arg, env);
		if (e_flg < 0)
			write_error();
	}
	else
		write_error();
	close(fd_in);
	close(new_pipe[1]);
	return (new_pipe[0]);
}

void	ft_lastjob(int fd, int file_fd)
{
	if (dup2(fd, file_fd) < 0)
		write_error();
	close(fd);
	close(file_fd);
}

void	ft_pipex(t_cmd *lst, int fd_in, char **env, int file_fd)
{
	int		new_pipe[2];

	printf("lst -> cmd = %s\n", lst -> path);
	if (lst -> path == NULL)
		ft_lastjob(fd_in, file_fd);
	else
	{
		if (pipe(new_pipe) < 0)
			write_error();
		fd_in = ft_middlejob(&lst, fd_in, env, new_pipe);
		ft_pipex(lst-> next, fd_in, env, file_fd);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		fd;
	t_cmd	*cmd;
	int		num;

	cmd = first_lst();
	num = 0;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		fd = ft_here_doc(argv[2]);
	else if (access(argv[1], F_OK) != 0)
		ft_printf("%s: No such file or directory", argv[1]);
	if (access(argv[argc - 1], F_OK) != 0)
	{
		num = open(argv[argc - 1], O_CREAT);
		if (num < 0)
			write_error();
	}
	else
		fd = open(argv[1], O_RDONLY);
	ft_create_lst(argc, argv, env, &cmd);
	ft_pipex(cmd, fd, env, num);
}
