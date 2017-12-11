/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 08:13:20 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/28 13:31:41 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_int(t_point point, char *num)
{
	int		l;
	int		i;
	int		k;
	int		p;
	int		skip;

	i = 0;
	l = ft_atoi_base(num, 16);
	skip = 0;
	p = 0;
	while (num[i] && skip == 0)
	{
		skip = 0;
		l = split_byte(num, i);
		if ((k = remain(num, i)) < 8)
			skip = 1;
		if (k <= 2)
			skip = 2;
		ft_reverse_bytes(&l, sizeof(l), skip);
		if (skip != 0)
			p = (8 - k) / 2;
		write(point.fd_2, &l, sizeof(l) - p);
		i += 8;
	}
}

void	print_exec_magic(t_point point)
{
	int	b;

	b = COREWAR_EXEC_MAGIC;
	ft_reverse_bytes(&b, sizeof(b), 0);
	write(point.fd_2, &b, sizeof(b));
}

void	print(t_point point)
{
	char	*lbl;
	int		i;

	i = -1;
	if ((lbl = ft_link(point.label, point.lbl_size)) == NULL)
		return ;
	point.size += ft_strlen(lbl) / 2;
	if (point.size >= CHAMP_MAX_SIZE)
	{
		print_error(6);
		return ;
	}
	if (point.lbl_err == 1)
	{
		print_error(4);
		return ;
	}
	point = create_file(point, point.file);
	print_exec_magic(point);
	write(point.fd_2, point.name, 132);
	ft_reverse_bytes(&point.size, sizeof(point.size), 0);
	write(point.fd_2, &point.size, sizeof(point.size));
	write(point.fd_2, point.comment, 2052);
	print_int(point, lbl);
}
