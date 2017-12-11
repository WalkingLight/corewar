/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 12:53:07 by oexall            #+#    #+#             */
/*   Updated: 2016/08/22 11:40:58 by kchetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static char	*ft_get_name(char *file)
{
	char	*n_name;
	char	*tmp;

	n_name = NULL;
	tmp = NULL;
	tmp = ft_strsub(file, 0,
			ft_strlen(file) - ft_strlen(ft_strrchr(file, '.')));
	n_name = ft_strjoin(tmp, ".cor");
	free(tmp);
	return (n_name);
}

int			ft_print(t_all *all)
{
	char	*n_name;

	n_name = NULL;
	n_name = ft_get_name(all->filename);
	if ((all->fd = open(n_name, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
		return (ft_error(all, "Failed to create new .cor file"));
	if (!ft_print_header(all))
		return (ft_error(all, "Failed to print header details."));
	if (!ft_print_cmds(all))
		return (ft_error(all, "Faield to print commands."));
	if (close(all->fd) < 0)
		return (ft_error(all, "Failed to close new .cor file"));
	free(n_name);
	return (1);
}
