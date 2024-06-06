/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkawahar <rkawahar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:57:05 by rkawahar          #+#    #+#             */
/*   Updated: 2024/06/06 20:28:26 by rkawahar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_connect_nord(t_cmd **lst, t_cmd *new)
{
	t_cmd	*tmp;

	tmp = (*lst)-> next;
	(*lst)-> next = new;
	new -> next = tmp;
	tmp -> pre = new;
	new -> pre = (*lst);
}

t_cmd	*first_lst(void)
{
	t_cmd	*nil;

	nil = (t_cmd *)malloc(sizeof(t_cmd));
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

void	ft_to_first(t_cmd **lst)
{
	while ((*lst)-> cmd != NULL)
		(*lst) = (*lst)-> pre;
}

void	ft_insert_info(t_cmd **lst, int argc, char **argv, char **env)
{
	int	i;

	i = 2;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		i++;
	while (i < argc - 1)
	{
		(*lst) = (*lst)-> next;
		ft_judge_absolute(*lst, argv, i);
		(*lst)-> path = ft_path((*lst)-> cmd, env);
		if (ft_strncmp((*lst)-> path, "nothing", 7) == 0)
			ft_printf("%s: command not found\n", (*lst)-> cmd);
		i++;
	}
	ft_to_first(lst);
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
		tmp = first_lst();
		ft_connect_nord(lst, tmp);
		num--;
	}
	ft_insert_info(lst, argc, argv, env);
	(*lst) = (*lst)-> next;
}
