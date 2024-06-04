/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:55:09 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/04 18:56:07 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_bin(char **bin)
{
	int	i;

	i = -1;
	while (bin[++i] != NULL)
	{
		printf("bin[%d] = %s\n", i,bin[i]);
	}
	free(bin);
}

char	*ft_path2(char **bin, char *cmd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (bin[i] != NULL)
	{
		tmp = ft_strjoin(bin[i], "/");
		tmp = ft_strjoin(tmp, cmd);
		if (tmp == NULL)
			malloc_error(7);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (tmp);
}

char	*ft_path(char *cmd, char **env)
{
	char	**bin;
	int		i;
	char	*ans;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	bin = ft_split(env[i], ':');
	if (bin == NULL)
		malloc_error(6);
	i = 0;
	while (i++ < 5)
		bin[0]++;
	ans = ft_path2(bin, cmd);
	ft_free_bin(bin);
	return (ans);
}
