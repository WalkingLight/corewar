/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 07:56:02 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/26 10:19:23 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_error(int num)
{
	if (num == 1)
		write(2, "Error1: Insufficient arguments\n", 30);
	if (num == 2)
		write(2, "Error2: File does not exist or already exists\n", 58);
	if (num == 3)
		write(2, "Error3: Invalid File\n", 21);
	if (num == 4)
		write(2, "Error4: Invalid characters in label\n", 36);
	if (num == 5)
		write(2, "Error5: Invalid command\n", 24);
	if (num == 6)
		write(2, "Error6: Champ size invalid\n", 28);
}
