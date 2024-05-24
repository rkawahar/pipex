/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:55:09 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/24 20:20:26 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char *cmd, char **env)
{
	char	**bin;
	char	*tmp;
	int		i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	bin = ft_split(env[i], ':');
	if (bin == NULL)
		malloc_error();
	i = 0;
	while (i++ < 5)
		bin[0]++;
	i = 0;
	while (bin[i])
	{
		tmp = ft_strtrim(bin[i], "/");
		tmp = ft_strtrim(tmp, cmd);
		if (tmp == NULL)
			malloc_error();
		if (access(tmp, F_OK) == 0)
			return (tmp);
		i++;
	}
	return (NULL);
}
