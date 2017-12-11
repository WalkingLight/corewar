/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:43:33 by rheukelm          #+#    #+#             */
/*   Updated: 2017/09/07 14:43:34 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_arg_type	ft_gettype(char *param)
{
	while (*param == ' ' || *param == '\t')
		param++;
	if (*param == 'r')
		return (T_REG);
	else if (*param == '%')
		return (T_DIR);
	return (T_IND);
}

char		*ft_gethex(int num, int len)
{
	char		*s;
	const char	hex[] = "0123456789abcdef";

	s = (char *)malloc(sizeof(char) * (len + 1));
	if (len & 1)
		*s++ = '0';
	s[len] = '\0';
	len--;
	while (len >= 0)
	{
		s[len] = hex[num & 0xf];
		num >>= 4;
		len--;
	}
	return (s);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
				free(split[i]);
			i++;
		}
		free(split);
	}
}

void		ft_print_list(t_cmd **c)
{
	int		i;
	t_cmd	*lst;

	printf("----------   Print list  ----------\n");
	lst = *c;
	i = 0;
	if (lst)
	{
		while (lst != NULL)
		{
			printf("list[%d]= lbl:%s\t\tcmd:%s\n", i, lst->label, lst->cmd);
			lst = lst->next;
			i++;
		}
	}
	else
		printf("Empty\n");
	printf("\n");
}

int			ft_isalldigit(char *num)
{
	int		i;

	i = 0;
	while (num[i])
	{
		if (num[i] <= 48 || num[i] >= 57)
			return (0);
		i++;
	}
	return (1);
}