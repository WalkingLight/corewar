/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 14:54:50 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/26 10:27:21 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	main(int ac, char **av)
{
	int			i;
	t_point		point;

	i = 1;
	point.i = 0;
	point.size = 0;
	ft_bzero(point.comment, 132);
	ft_bzero(point.comment, 2052);
	if (ac == 1)
	{
		print_error(1);
		return (0);
	}
	while (i < ac)
	{
		point.file = (char *)malloc(sizeof(char) * ft_strlen(av[i]));
		if ((text(point, av[i])) == -1)
		{
			print_error(3);
			return (0);
		}
		write(1, "Done\n", 5);
		i++;
	}
	return (0);
}
