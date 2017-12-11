/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:09:35 by rheukelm          #+#    #+#             */
/*   Updated: 2017/09/20 12:19:24 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char	*ft_append(char *s1, char *s2)
{
	int		i;
	int		len;
	char	*out;

	if (s1 == NULL)
		return (s2);
	if ((out = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))
	+ 1)) == NULL)
		return (NULL);
	out = ft_strcpy(out, s1);
	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		out[len] = s2[i];
		len++;
		i++;
	}
	out[len] = '\0';
	free(s1);
	free(s2);
	return (out);
}

static char	*ft_get_params(t_cmd *c, char *cmd, int i, char *str)
{
	int		index;
	char	**params;

	params = NULL;
	index = ft_getindex(cmd);
	cmd = cmd + ft_strlen(op_tab[index].name);
	params = ft_strsplit(ft_trim(cmd), SEPARATOR_CHAR);
	while (params[++i])
	{
		if (ft_gettype(params[i]) == T_REG)
		{
			if (ft_get_reg(params[i]) == NULL)
				return (NULL);
			str = ft_append(str, ft_get_reg(params[i]));
		}
		else if (ft_gettype(params[i]) == T_DIR)
		{
			if (ft_get_dir(c, params[i], op_tab[index].is_index) == NULL)
				return (NULL);
			str = ft_append(str, ft_get_dir(c, params[i], op_tab[index].is_index));
		}
		else if (ft_gettype(params[i]) == T_IND)
			str = ft_append(str, ft_get_ind(params[i]));
	}
	ft_free_split(params);
	return (str);
}

char		*ft_hex(t_cmd **lst)
{
	int		i;
	char	*str;
	t_cmd	*c;

	str = NULL;
	c = *lst;
	while (c)
	{
		if ((c->cmd || (c->cmd && c->label)) && !ft_isempty(c->cmd))
		{
			i = ft_getindex(c->cmd);
			str = ft_append(str, ft_gethex(i + 1, 2));
			if (op_tab[i].has_acb)
				str = ft_append(str, ft_gethex(ft_getacb(c->cmd), 2));
			if (ft_get_params(c, c->cmd, -1, NULL) == NULL)
				return (NULL);
			str = ft_append(str, ft_get_params(c, c->cmd, -1, NULL));
		}
		c = c->next;
	}
	return (str);
}
