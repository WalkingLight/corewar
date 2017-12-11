/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:05:29 by rheukelm          #+#    #+#             */
/*   Updated: 2017/08/25 16:04:52 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ASM_H
# define	ASM_H

# include <stdio.h>
# include "op.h"
# include "includes/libft.h"

# define	TRUE 1
# define	FALSE 0

typedef struct		s_cmd
{
	char			*label;
	char			*cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

void		ft_link(char **str, int len);

void		ft_push_cmd(t_cmd **begin, char *cmd, char *lbl);
void		ft_print_list(t_cmd **c);
void		ft_free_cmd(t_cmd **begin);

int			ft_valid(t_cmd **c, char *cmd, char *lbl);

char		*ft_hex(t_cmd **c);

char		*ft_get_lbl(t_cmd *c, char *lbl);

char		*ft_get_reg(char *reg);
char		*ft_get_dir(t_cmd *c, char *cmd, int is_index);
char		*ft_get_ind(char *cmd);

int			ft_getacb(char *str);

char		*ft_trim(char *str);
int			ft_space(char c);
int			ft_find(char *str, char c);
int			ft_isempty(char *str);
int			ft_getindex(char *str);
void		ft_free_split(char **split);
int			ft_isalldigit(char *num);

t_arg_type	ft_gettype(char *param);
char		*ft_gethex(int num, int len);

#endif
