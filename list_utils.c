/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:57:05 by rkawahar          #+#    #+#             */
/*   Updated: 2024/05/24 18:40:11 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_connect_nord(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	(*lst)-> next = tmp;
	(*lst)-> next = new;
	new -> next = tmp;
	tmp -> pre = new;
	new -> pre = (*lst);
}

t_cmd	*first_lst(void)
{
	t_cmd	*nil;

	nil = (char *)malloc(sizeof(t_cmd));
	if (nil == NULL)
	{
		write(2, "malloc error", 13);
		exit(1);
	}
	nil -> next = nil;
	nil -> cmd = NULL;
	nil -> path = NULL;
	nil -> arg = NULL;
	nil -> pre = nil;
	return (nil);
}

void	ft_insert_info(t_cmd **lst, int num, char **argv, char **env)
{
	int i;

	i = 0;
	while (i < num)
	{
		
	}
}

void	ft_create_lst(int argc, char **argv, char **env, t_cmd **lst)
{
	t_cmd	*tmp;
	int		num;

	if (ft_strncmp(argv[1], "fere_doc", 9) == 0)
		num = argc - 4;
	else
		num = argc - 3;
	while (0 < num)
	{
		tmp = (t_cmd *)malloc(sizeof(t_cmd));
		tmp = first_lst();
		ft_connect_nord(lst, tmp);
	}
	ft_insert_info(lst, num, argv, env);
}
