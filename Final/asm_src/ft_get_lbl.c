/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_lbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:09:35 by rheukelm          #+#    #+#             */
/*   Updated: 2017/09/28 11:01:14 by cpauwels         ###   ########.fr       */
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
			if (g_op_tab[i].is_index != 1)
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
	if (g_op_tab[i].has_acb)
		out++;
	cmd = cmd + ft_strlen(g_op_tab[i].name);
	while (*cmd == ' ' || *cmd == '\t')
		cmd++;
	params = ft_strsplit(cmd, SEPARATOR_CHAR);
	out += ft_count(i, params);
	ft_free_split(params);
	return (out);
}

static int	ft_look_down(t_cmd *c, char *lbl, int i)
{
	int		out;

	out = 0;
	while (c)
	{
		if (c->label)
			if (ft_strncmp(c->label, lbl, i) == 0)
				return (out);
		if (c->cmd)
			out += ft_count_line(c->cmd);
		c = c->next;
	}
	return (0);
}

static int	ft_look_up(t_cmd *c, char *lbl, int i)
{
	int		out;

	out = 0;
	while (c)
	{
		if (c->cmd)
			out -= ft_count_line(c->cmd);
		if (c->label)
			if (ft_strncmp(c->label, lbl, i) == 0)
				return (out);
		c = c->prev;
	}
	return (0);
}

char		*ft_get_lbl(t_cmd *c, char *lbl)
{
	int		out;
	int		i;

	i = 0;
	while (lbl[i] != ' ' && lbl[i] != '\t' && lbl[i])
		i++;
	out = 0;
	out = ft_look_down(c, lbl, i);
	if (out == 0)
		out = ft_look_up(c->prev, lbl, i);
	if (out == 0)
		return (NULL);
	return (ft_gethex(out, 4));
}
