/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:09:35 by rheukelm          #+#    #+#             */
/*   Updated: 2017/09/21 13:14:54 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	ft_count(int i, char **params)
{
	int		k;
	int		out;

	k = -1;
	out = 0;
	while (params[++k])
	{
		if (ft_gettype(params[k]) == T_REG)
			out++;
		else if (ft_gettype(params[k]) == T_DIR && params[k][1] != LABEL_CHAR)
			if (op_tab[i].is_index != 1)
				out += 4;
			else
				out += 2;
		else if (ft_gettype(params[k]) == T_DIR && params[k][1] == LABEL_CHAR)
			out += 2;
		else
			out += 2;
	}
	return (out);
}

static int	ft_count_line(char *cmd)
{
	int		i;
	int		out;
	char	**params;

	out = 0;
	if ((i = ft_getindex(cmd)) != -1)
		out++;
	if (op_tab[i].has_acb)
		out++;
	cmd = cmd + ft_strlen(op_tab[i].name);
	while (*cmd == ' ' || *cmd == '\t')
		cmd++;
	params = ft_strsplit(cmd, SEPARATOR_CHAR);
	out += ft_count(i, params);
	ft_free_split(params);
	return (out);
}

static int	ft_look_down(t_cmd *c, char *lbl)
{
	int		out;

	out = 0;
	while (c)
	{
		if (c->label)
			if (ft_strncmp(c->label, lbl, ft_strlen(c->label)) == 0 &&
			(ft_strlen(c->label) == ft_strlen(lbl)))
				return (out);
		if (c->cmd)\
			out += ft_count_line(c->cmd);
		c = c->next;
	}
	return (0);
}

static int	ft_look_up(t_cmd *c, char *lbl)
{
	int		out;

	printf("ft_look_up called\n");
	out = 0;
	if (c->prev != NULL)
	{
		c = c->prev;
		while (c)
		{
			printf("c->cmd:'%s'\n", c->cmd);
			if (c->cmd)
				out -= ft_count_line(c->cmd);
			printf("c->label:'%s'\n", c->label);
			if (c->label)
				if (ft_strncmp(c->label, lbl, ft_strlen(c->label)) == 0 &&
					(ft_strlen(c->label) == ft_strlen(lbl)))
					return (out);
			c = c->prev;
		}
	}
	printf("ft_look_up ended\n");
	return (0);
}

char		*ft_get_lbl(t_cmd *c, char *lbl)
{
	int		out;

	out = 0;
	printf("get_lbl lbl:'%s'\n", lbl);
	out = ft_look_down(c, lbl);
	printf("1 out:%d\n", out);
	if (out == 0)
		out = ft_look_up(c, lbl);
	printf("2 out:%d\n", out);
	if (out == 0)
		return (NULL);
	return (ft_gethex(out, 4));
}
