/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:55:09 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/05 16:07:36 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_bin(char **bin)
{
	int	i;

	i = 0;
	while (bin[i])
		free(bin[i++]);
	free(bin);
}

char	*ft_shift(char *str, int i)
{
	char	*ans;
	int		l;

	ans = (char *)malloc(ft_strlen(str) - i + 1);
	if (ans == NULL)
		malloc_error(10);
	l = 0;
	while (str[i])
	{
		ans[l] = str[i];
		i++;
		l++;
	}
	ans[l] = '\0';
	free(str);
	return (ans);
}

char	*ft_path2(char **bin, char *cmd)
{
	char	*tmp1;
	char	*tmp;
	int		i;

	i = 0;
	while (bin[i] != NULL)
	{
		tmp1 = ft_strjoin(bin[i], "/");
		tmp = ft_strjoin(tmp1, cmd);
		free(tmp1);
		if (tmp == NULL)
			malloc_error(7);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
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
	bin[0] = ft_shift(bin[0], 5);
	ans = ft_path2(bin, cmd);
	ft_free_bin(bin);
	return (ans);
}
