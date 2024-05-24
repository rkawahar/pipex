/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:40:06 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/24 20:13:57 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	checker(char al, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == al)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*ans;

	if (s1 == NULL || set == NULL)
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (checker(s1[start], set))
		start++;
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	while (checker(s1[end], set))
		end--;
	ans = (char *)malloc(sizeof(char) * (end - start + 2));
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		ans[i++] = s1[start++];
	ans[i] = '\0';
	return (ans);
}
