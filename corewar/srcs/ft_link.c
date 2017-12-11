/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:09:35 by rheukelm          #+#    #+#             */
/*   Updated: 2017/09/21 13:53:31 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	ft_addlabel(t_cmd **c, char *str)
{
	char	*lbl;
	char	*cmd;
	int		i;
	int		error;

	error = FALSE;
	i = ft_find(str, LABEL_CHAR);
	lbl = ft_strsub(str, 0, i);
	cmd = ft_strdup(&str[i + 1]);
	i = -1;
	while (lbl[++i])
		if (ft_find(LABEL_CHARS, lbl[i]) < 0)
			error = TRUE;
	if (ft_strlen(cmd) <= 0 || ft_isempty(cmd))
		ft_push_cmd(c, NULL, lbl);
	else if (ft_strlen(cmd) > 0 && !ft_isempty(cmd))
		if (ft_valid(c, cmd, lbl) == TRUE)
			error = TRUE;
	free(lbl);
	free(cmd);
	return (error);
}

void		ft_link(char **str, int len)
{
	int		i;
	int		error;
	t_cmd	*c;
	char	*out;

	i = 0;
	c = NULL;
	error = FALSE;
	while (i < len && error == FALSE)
	{
		if (ft_find(str[i], LABEL_CHAR) > -1
			&& str[i][ft_find(str[i], LABEL_CHAR) - 1] != DIRECT_CHAR)
			error = ft_addlabel(&c, str[i]);
		else if (ft_trim(str[i])[0] != COMMENT_CHAR && !ft_isempty(str[i]))
			error = ft_valid(&c, str[i], NULL);
		i++;
	}
	ft_print_list(&c);
	out = ft_hex(&c);
	ft_free_cmd(&c);
	if (error == TRUE || out == NULL)
	{
		ft_putendl_fd("Erorr: Invalid command.", 2);
	}
	printf("----------   HEX values  ----------\n%s\n\n", out);
	free(out);
}
