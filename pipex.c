/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:45:14 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/27 21:25:31 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(t_cmd **lst, int fd_in, char **env)
{
	int		num;
	pid_t	pid;
	int		new_pipe[2];

	(*lst) = (*lst)-> next;
	if ((*lst)-> path = NULL)
		ft_lastjob();
	else
	{
		ft_middlejob(lst, fd_in, env);
		ft_pipex(lst, fd_in, env);
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
		write_error();
	}
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		fd = ft_here_doc(argv[2]);
	else
		fd = open(argv[1], O_RDONLY);
	ft_create_lst(argc, argv, env, &cmd);
	ft_pipex(&cmd, fd, env);
}
