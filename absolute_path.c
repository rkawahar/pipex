/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:15:52 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/05 18:02:32 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
