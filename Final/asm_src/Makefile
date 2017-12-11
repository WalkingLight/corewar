# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/14 14:46:37 by cpauwels          #+#    #+#              #
#    Updated: 2017/10/01 07:39:29 by cpauwels         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC = main.c error.c text.c hex.c file.c check.c print.c reverse.c \
	  ft_atoi_base.c split.c ft_free.c\
	  ft_get_lbl.c ft_get_parems.c ft_getacb.c ft_hex_lbl.c ft_link.c \
	  ft_list.c ft_misc.c ft_misc2.c ft_valid.c op.c
LIB = ../libft/libft.a
FLAG = -Wall -Werror -Wextra -iquoteincludes

NONE = \x1b[0m
OK = \x1b[32;01m
WARN = \x1b[33;01m

all: $(NAME)

$(NAME):
	@echo "$(OK)----------   Compile ASM   ----------$(NONE)"
	@gcc -o $(NAME) $(SRC) $(FLAG) $(LIB)
	@echo "$(OK)----------     Success     ----------$(NONE)\n"
	
clean:
	@echo "$(WARN)----------    Clean ASM    ----------$(NONE)"
	@rm -f $(NAME)
	@echo "Removed ./asm"
	@echo "$(WARN)----------     Success     ----------$(NONE)\n"

fclean: clean
	@echo "$(WARN)----------    FClean ASM   ----------$(NONE)"
	@rm -f *.cor
	@echo "Removed ./asm"
	@echo "$(WARN)----------     Success     ----------$(NONE)\n"

re: fclean all
