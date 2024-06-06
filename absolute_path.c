/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:15:52 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/06 20:03:20 by rkawahar         ###   ########.fr       */
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

void	ft_judge_absolute(t_cmd *lst, char **argv, int index)
{
	char	**tmp;
	int		i;

	i = 0;
	lst -> arg = ft_split(argv[index], ' ');
	if (lst -> arg == NULL)
		malloc_error(4);
	if (lst -> arg[0][0] == '/')
	{
		tmp = ft_split(lst -> arg[0], '/');
		if (tmp == NULL)
			malloc_error(11);
		while (tmp[i])
			i++;
		i--;
		lst -> arg[0] = tmp[i];
	}
	lst -> cmd = lst -> arg[0];
}
