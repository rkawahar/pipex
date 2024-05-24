/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 11:45:14 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/24 17:29:00 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		fd;
	t_cmd	*cmd;

	cmd = first_lst();
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		fd = ft_here_doc(argv[2]);
	else
		fd = open(argv[1], O_RDONLY);
	ft_create_lst(argc, argv, env, &cmd);
}
