/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:45:14 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/04 07:08:57 by kawaharadar      ###   ########.fr       */
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
	char	tmp;
	char	*str;
	int		read_byte;

	str = (char *)malloc(1);
	str[0] = '\0';
	read_byte = 1;
	while (1)
	{
		read_byte = read(fd, &tmp, 1);
		if (read_byte == 0)
			break;
		else if (read_byte < 0)
			write_error();
		str = re_create(str, tmp);
	}
	close(fd);
	read_byte = write(file_fd, str, ft_strlen(str));
	if (read_byte < 0)
		write_error();
	close(file_fd);
}

void	ft_pipex(t_cmd *lst, int fd_in, char **env, int file_fd)
{
	int		new_pipe[2];

	if (lst -> path == NULL)
		ft_lastjob(fd_in, file_fd);
	else
	{
		if (pipe(new_pipe) < 0)
			write_error();
		fd_in = ft_middlejob(&lst, fd_in, env, new_pipe);
		ft_pipex(lst-> next, fd_in, env, file_fd);
	}
	exit(0);
}

void	ft_decide_fd(int *fd, int *last_file_fd, char **argv, char *file)
{
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		*fd = ft_here_doc(argv[2]);
		*last_file_fd = open(file , O_CREAT | O_WRONLY | O_APPEND, 0000644);
	}
	else if (access(argv[1], F_OK) != 0)
	{
		ft_printf("%s: No such file or directory", argv[1]);
		exit(1);
	}
	else
	{
		*fd = open(argv[1], O_RDWR);
		*last_file_fd = open(file , O_CREAT | O_TRUNC | O_WRONLY, 0000644);
	}
}

int	main(int argc, char **argv, char **env)
{
	int		fd;
	t_cmd	*cmd;
	int		last_file_fd;
	char	*file;

	cmd = first_lst();
	file = argv[argc - 1];
	last_file_fd = -1;
	fd = -1;
	if (argc == 1)
		exit(0);
	ft_decide_fd(&fd, &last_file_fd, argv, file);
	if (last_file_fd < 0)
		write_error();
	ft_create_lst(argc, argv, env, &cmd);
	ft_pipex(cmd, fd, env, last_file_fd);
}

#include <libc.h>

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}