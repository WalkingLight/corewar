/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 07:31:40 by cpauwels          #+#    #+#             */
/*   Updated: 2017/08/17 08:41:30 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define NAME_FILE_TYPE ".cor"

void	print_error(int num);

typedef struct	s_point
{
	char	name[128];
	char	comment[2048];
	char	*line;
	int		fd;
}				t_point;

int		text(char *file_name);
void	create_file(char *s);

#endif
