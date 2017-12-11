/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_val_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 09:35:47 by oexall            #+#    #+#             */
/*   Updated: 2016/08/22 11:42:25 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			ft_iswhiteonly(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
	return (1);
}

int			ft_val_label(t_all *all, char *label)
{
	char	*lbl;
	char	*cmd;
	int		i;
	int		res;

	res = 1;
	i = ft_oneof(LABEL_CHAR, label);
	lbl = ft_strsub(label, 0, i);
	cmd = ft_strdup(&label[i + 1]);
	i = -1;
	//printf("val_label -> lbl:%s, cmd:%s\n", lbl, cmd);
	while (lbl[++i])
		if (ft_oneof(lbl[i], LABEL_CHARS) < 0)
			res = ft_error(all, "Invalid Character in Label.");
	if (res && (ft_strlen(cmd) <= 0 || ft_iswhiteonly(cmd)))
	{
		//printf("--1--\n");
		ft_push_back_cmd(&all->cmd, NULL, lbl);
	}
	else if (res && ft_strlen(cmd) > 0 && !ft_iswhiteonly(cmd))
	{
		//printf("--2--\n");
		if (!(ft_is_valid(all, ft_trimsp(cmd), lbl)))
		{
			//printf("--3--\n");
			res = ft_error(all, "Invalid Command.");
		}
	}
	free(lbl);
	free(cmd);
	return (res);
}
