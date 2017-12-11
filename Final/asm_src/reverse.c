/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 06:30:44 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/20 11:58:34 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_reverse_bytes(void *mem, size_t size, int skip)
{
	int		j;
	int		i;
	char	*tmp;
	char	*ptr;

	if (skip != 2)
	{
		if (skip == 1)
			i = size - 2;
		else
			i = size - 1;
		j = 0;
		ptr = (char *)mem;
		tmp = (char *)malloc(size);
		ft_memcpy(tmp, mem, size);
		while (i >= 0)
		{
			ptr[j] = tmp[i];
			j++;
			i--;
		}
		free(tmp);
	}
}

void	trim_first(void *mem, size_t size)
{
	int		j;
	char	*ptr;
	char	*tmp;

	j = 0;
	ptr = (char *)mem;
	tmp = (char *)malloc(size);
	ft_memcpy(tmp, mem, size);
	while (j + 2 <= (int)size)
	{
		ptr[j] = tmp[j + 1];
		ptr[j + 1] = tmp[j + 2];
		j++;
	}
	free(tmp);
}
