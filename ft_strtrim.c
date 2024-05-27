/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:40:06 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/27 13:50:15 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ans = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (ans == NULL)
		return (NULL);
	ft_strlcpy(ans, s1, len1 + 1);
	i = 0;
	while (i < len2)
	{
		ans[len1 + i] = s2[i];
		i++;
	}
	ans[i + len1] = '\0';
	return (ans);
}
