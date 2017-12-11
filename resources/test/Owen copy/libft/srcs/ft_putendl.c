/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 15:22:07 by khansman          #+#    #+#             */
/*   Updated: 2016/05/15 11:01:10 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(char const *s)
{
	int	k;

	k = 0;
	while (s[k] != '\0')
		k++;
	write(1, s, k);
	write(1, "\n", 1);
}
