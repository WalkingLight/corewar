/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:18:26 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/26 09:50:39 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		label_chars(char s)
{
	int	i;
	int	value;

	value = 0;
	i = 0;
	while (LABEL_CHARS[i] != '\0')
	{
		if (LABEL_CHARS[i] == s)
			value++;
	}
	if (value > 0)
		return (0);
	return (-1);
}
