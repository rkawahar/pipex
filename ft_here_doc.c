/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kawaharadaryou <kawaharadaryou@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:37:17 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/30 00:34:13 by kawaharadar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_eof(char *eof)
{
	char	*ans;
	int		i;

	ans = (char *)malloc(ft_strlen(eof) + 2);
	if (ans == NULL)
		malloc_error();
	ans[0] = '\n';
	i = 1;
	while (eof[i - 1])
	{
		ans[i] = eof[i - 1];
		i++;
	}
	ans[i] = '\n';
	return (ans);
}

int	checker(char *str, char *eof)
{
	int	i;

	i = 0;
	eof = ft_eof(eof);
	while (str[i])
	{
		if (ft_strncmp(&str[i], eof, ft_strlen(eof)) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*re_create(char *str, char tmp)
{
	char	*ans;
	int		i;

	ans = (char *)malloc(tmp + 1);
	if (ans == NULL)
		malloc_error();
	i = -1;
	while (str[++i])
		ans[i] = str[i];
	ans[i] = tmp;
	ans[i + 1] = '\0';
	free(str);
	return (ans);
}

char	*pipex_gnl(char *eof)
{
	char	*ans;
	char	tmp;
	int		len;

	ans = (char *)malloc(sizeof(1));
	if (ans == NULL)
		malloc_error();
	ans[0] = '\0';
	len = 0;
	while (checker(ans, eof) == 0)
	{
		read(0, &tmp, 1);
		len++;
		ans = re_create(ans, tmp);
	}
	ans[len - ft_strlen(eof) - 2] = '\0';
	return (ans);
}

int	ft_here_doc(char *eof)
{
	int		pipe1[2];
	char	*str;

	str = pipex_gnl(eof);
	if (pipe(pipe1) < 0)
		write_error();
	write(pipe1[1], str, ft_strlen(str));
	close(pipe1[1]);
	return (pipe1[0]);
}
