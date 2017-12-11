/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:09:35 by rheukelm          #+#    #+#             */
/*   Updated: 2017/09/20 11:52:40 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

char		*ft_get_reg(char *cmd)
{
	char	*out;

	while (*cmd == ' ' || *cmd == 'r')
		cmd++;
	if (ft_atoi(cmd) <= 0 || ft_atoi(cmd) >= REG_NUMBER + 1)
		return (NULL);
	out = ft_gethex(ft_atoi(cmd), 2);
	return (out);
}

char		*ft_get_dir(t_cmd *c, char *cmd, int is_index)
{
	while (*cmd == ' ' || *cmd == '\t')
		cmd++;
	if (cmd[0] == DIRECT_CHAR && cmd[1] != LABEL_CHAR)
	{
		if (!is_index)
			return (ft_gethex(ft_atoi(&cmd[1]), 8));
		else
			return (ft_gethex(ft_atoi(&cmd[1]), 4));
	}
	else if (cmd[0] == DIRECT_CHAR && cmd[1] == LABEL_CHAR)
		return (ft_get_lbl(c, &cmd[2]));
	return (NULL);
}

char		*ft_get_ind(char *cmd)
{
	return (ft_gethex(ft_atoi(cmd), 2));
}
