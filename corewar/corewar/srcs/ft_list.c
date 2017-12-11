/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:09:35 by rheukelm          #+#    #+#             */
/*   Updated: 2017/09/21 13:09:54 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_cmd	*ft_new_cmd(char *cmd, char *lbl)
{
	t_cmd	*tmp;

	tmp = (t_cmd *)malloc(sizeof(t_cmd));
	tmp->cmd = NULL;
	if (cmd != NULL)
		tmp->cmd = ft_strdup(cmd);
	tmp->label = NULL;
	if (lbl != NULL)
		tmp->label = ft_strdup(lbl);
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

void			ft_push_cmd(t_cmd **begin, char *cmd, char *lbl)
{
	t_cmd	*lst;

	lst = *begin;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = ft_new_cmd(cmd, lbl);
		lst->next->prev = lst;
	}
	else
		*begin = ft_new_cmd(cmd, lbl);
}

void			ft_free_cmd(t_cmd **begin)
{
	t_cmd	*list;
	t_cmd	*tmp;

	list = NULL;
	tmp = NULL;
	list = *begin;
	if (list)
	{
		while (list)
		{
			tmp = list;
			list = list->next;
			if (tmp->cmd)
				free(tmp->cmd);
			if (tmp->label)
				free(tmp->label);
			free(tmp);
		}
		*begin = NULL;
	}
}