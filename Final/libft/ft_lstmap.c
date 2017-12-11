/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 09:41:17 by cpauwels          #+#    #+#             */
/*   Updated: 2017/06/09 09:53:37 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*curr;
	t_list	*save;

	curr = (t_list *)malloc(sizeof(t_list));
	curr = f(lst);
	save = curr;
	tmp = lst->next;
	while (tmp != NULL)
	{
		new = (t_list *)malloc(sizeof(t_list));
		new = f(tmp);
		tmp = tmp->next;
		curr->next = new;
		curr = curr->next;
		new = NULL;
	}
	return (save);
}
