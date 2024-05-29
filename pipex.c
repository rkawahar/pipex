/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:45:14 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/30 00:26:41 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_middlejob(t_cmd **lst, int fd_in, char **env, int *new_pipe)
{
	pid_t	pid;
	int		e_flg;

	pid = fork();
	if (pid > 0)
		wait(NULL);
	else if (pid == 0)
	{
		if (dup2(fd_in, 0) < 0 || dup2(new_pipe[1], 1) < 0)
			exit(1);
		e_flg = execve((*lst)-> path, (*lst)-> arg, env);
		if (e_flg < 0)
			exit(1);
	}
	else
		write_error();
	close(fd_in);
	close(new_pipe[1]);
	if (e_flg < 0)
	{
		close(new_pipe[0]);
		write_error();
	}
	return (new_pipe[0]);
}

void	ft_lastjob(int fd, int file_fd)
{
	
}

void	ft_pipex(t_cmd **lst, int fd_in, char **env, int file_fd)
{
	int		num;
	int		new_pipe[2];

	(*lst) = (*lst)-> next;
	if ((*lst)-> path = NULL)
		ft_lastjob(fd_in, file_fd);
	else
	{
		if (pipe(new_pipe) < 0)
			write_error();
		fd_in = ft_middlejob(lst, fd_in, env, new_pipe);
		ft_pipex(lst, fd_in, env, file_fd);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		fd;
	t_cmd	*cmd;
	int		num;

	cmd = first_lst();
	if (access(argv[1], F_OK) != 0)
		ft_printf("%s: No such file or directory", argv[1]);
	if (acccess(argv[argc - 1], F_OK) != 0)
	{
		num = open(argv[argc - 1], 'a');
		if (num < 0)
			write_error();
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		fd = ft_here_doc(argv[2]);
	else
		fd = open(argv[1], O_RDONLY);
	ft_create_lst(argc, argv, env, &cmd);
	ft_pipex(&cmd, fd, env, num);
}
