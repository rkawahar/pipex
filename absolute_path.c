/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:15:52 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/14 15:10:31 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*ans;
	size_t	size;
	size_t	copy_size;

	size = ft_strlen(s1);
	ans = (char *)malloc(sizeof(char) * (size + 1));
	if (ans == NULL)
		return (NULL);
	copy_size = ft_strlcpy(ans, s1, size + 1);
	return (ans);
}

void	ft_judge_absolute(t_cmd *lst, char **argv, int index, char **env)
{
	int		i;

	i = 0;
	lst -> arg = ft_split(argv[index], ' ');
	if (lst -> arg == NULL)
		malloc_error(4);
	if (lst -> arg[0][0] == '/')
		lst -> path = lst -> arg[0];
	else
	{
		lst -> cmd = lst -> arg[0];
		lst -> path = ft_path(lst -> cmd, env);
	}
}
