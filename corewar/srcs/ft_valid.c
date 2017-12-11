/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:09:35 by rheukelm          #+#    #+#             */
/*   Updated: 2017/09/20 14:26:24 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static char	**ft_count_params(char *cmd, int i, int len)
{
	int		count;

	count = 0;
	while (cmd[len] != '\0')
	{
		if ((cmd[len] == DIRECT_CHAR) || (cmd[len] >= '0' && cmd[len] >= '9') ||
		((cmd[len] == 'r') && (cmd[len] >= '0' && cmd[len] <= '9')))
			(count == 0) ? count = 1 : 0;
		(cmd[len] == SEPARATOR_CHAR) ? count++ : 0;
		len++;
	}
	len = 0;
	while (cmd[len] != '\0')
	{
		if ((cmd[len] == DIRECT_CHAR) || (cmd[len] >= '0' && cmd[len] <= '9') ||
		((cmd[len] == SEPARATOR_CHAR) && (cmd[len + 1] >= '0' && cmd[len + 1] <= '9')))
			break ;
		len++;
	}
	if (count != op_tab[i].no_args)
		return (NULL);
	return (ft_strsplit(&cmd[len - 1], SEPARATOR_CHAR));
}

static int	ft_check(int check_no, int i)
{
	int		k;

	k = 0;
	while (k < op_tab[i].no_args)
	{
		if (check_no == 1)
			if (T_REG & op_tab[i].type[k])
				return (TRUE);
		if (check_no == 2)
			if (T_DIR & op_tab[i].type[k])
				return (TRUE);
		if (check_no == 3)
			if (T_IND & op_tab[i].type[k])
				return (TRUE);
		k++;
	}
	return (-1);
}

static int	ft_validate_params(char **tab, int i)
{
	int		j;
	int		res;

	j = 0;
	res = -1;
	if (tab == NULL)
		return (TRUE);
	while (tab[j] != '\0')
	{
		if (ft_strncmp(ft_trim(tab[j]), "r", 1) == 0)
			res = ft_check(1, i);
		else if (ft_strncmp(ft_trim(tab[j]), "%", 1) == 0)
			res = ft_check(2, i);
		else if (ft_isalldigit(ft_trim(tab[j])))
			res = ft_check(3, i);
		if (res == -1)
			return (TRUE);
		j++;
	}
	return (FALSE);
}

int			ft_valid(t_cmd **c, char *cmd, char *lbl)
{
	int		i;
	int		len;
	int		error;
	char	*tmp;
	char	**tab;

	i = 0;
	len = 0;
	error = TRUE;
	tmp = ft_trim(cmd);
	ft_push_cmd(c, tmp, lbl);
	while (i < 16 && error == TRUE)
	{
		len = ft_strlen(op_tab[i].name);
		if ((ft_strncmp(tmp, op_tab[i].name, len) == 0) && (tmp[len] == ' ' 
		|| tmp[len] == '\t'))
			error = FALSE;
		i++;
	}
	if ((tab = ft_count_params(tmp, --i, len)) == NULL)
		return (TRUE);
	if (ft_validate_params(tab, i) == TRUE)
		return (TRUE);
	ft_free_split(tab);
	return (error);
}
