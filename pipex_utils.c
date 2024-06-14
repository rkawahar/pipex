/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:24:13 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/14 13:50:53 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *s)
{
	int	ans;

	ans = 0;
	while (*s)
	{
		ans++;
		s++;
	}
	return (ans);
}

void	malloc_error(int i)
{
	ft_printf("number = %d\n", i);
	write(2, "malloc error", 13);
	exit(1);
}

void	write_error(char *str)
{
	if (str == NULL)
	{
		perror(NULL);
		exit(1);
	}
	else
	{
		ft_printf("%s: ", str);
		perror(NULL);
		exit(1);
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	dst = (char *)dst;
	len = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
