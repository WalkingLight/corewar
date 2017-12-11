/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:01:03 by rheukelm          #+#    #+#             */
/*   Updated: 2017/08/25 16:04:55 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
 0b | 68 |          01 |       00 0f | 00 01
 06 | 64 |          01 | 00 00 00 00 |    01
 01 |    | 00 00 00 01 |             |
 09 |    |       ff fb |             |
*/

int			main(void)
{
	
	char	*str[] = {	"enter:		sti r1,%:live,%1",
						"			and r1,%0,r1",
						"xxx:		live %1",
						"			zjmp %:live"};
						ft_link(str, 5);
	/*
	char	*str[] = {	"sti	r1, %:live, %1",
						"sti	r1, %:live2, %1",
						"ld		%1, r3",
						"ld		%33, r6",
						"forks:",
						"add	r2, r3, r2",
						"xor	r2, %15, r4",
						"live2:",
						"		live 	%4",
						"zjmp	%:endwhile",
						"fork	%:forks",
						"ld		%0, r4",
						"zjmp	%:forks",
						"endwhile:",
						"ld		%0, r4",
						"live:",
						"live 	%4",
						"zjmp 	%:live"};
						ft_link(str, 19);
	*/
	return (0);
}
