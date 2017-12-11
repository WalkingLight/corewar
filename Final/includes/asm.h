/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 07:31:40 by cpauwels          #+#    #+#             */
/*   Updated: 2017/09/28 07:44:14 by cpauwels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"

# define NAME_FILE_TYPE ".cor"

void	print_error(int num);

typedef struct	s_point
{
	char	*file;
	char	name[132];
	int		name_byte;
	char	comment[2052];
	char	**label;
	int		lbl_err;
	int		list_err;
	char	*line;
	int		fd;
	int		fd_2;
	int		size;
	int		lbl_size;
	int		i;
}				t_point;

# define	TRUE 1
# define	FALSE 0

t_point		ft_free(t_point point);
int			text(t_point point, char *file_name);
t_point		create_file(t_point point, char *s);
int			check_label(char *s);
t_point		get_lines(t_point point, char *line);
void		print(t_point point);
char		*atoh(char *str);
void		ft_reverse_bytes(void *mem, size_t size, int skip);
long int	ft_atoi_base(char *str, int base);
int			split_byte(char *s, int i);
int			remain(char *s, int i);
void		trim_first(void *mem, size_t size);
char		*set_size(char *s);

typedef struct		s_cmd
{
	char			*label;
	char			*cmd;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

char		*ft_link(char **str, int len);

void		ft_push_cmd(t_cmd **begin, char *cmd, char *lbl);
void		ft_print_list(t_cmd **c);

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
void		ft_free_cmd(t_cmd **begin);
int			ft_isalldigit(char *num);
t_arg_type	ft_gettype(char *param);
char		*ft_gethex(int num, int len);

#endif
