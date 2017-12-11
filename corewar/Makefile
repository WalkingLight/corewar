# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/24 14:19:17 by rheukelm          #+#    #+#              #
#    Updated: 2017/09/22 10:36:43 by rheukelm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS= -Wall -Werror -Wextra
NAME= asm

SRCS= 	./srcs/main.c \
		./srcs/op.c \
		./srcs/ft_link.c \
		./srcs/ft_valid.c \
		./srcs/ft_list.c \
		./srcs/ft_hex_lbl.c \
		./srcs/ft_get_parems.c \
		./srcs/ft_getacb.c \
		./srcs/ft_get_lbl.c \
		./srcs/ft_misc.c \
		./srcs/ft_misc2.c

all: $(NAME)

$(NAME):
	@echo "----------Compiling libft----------"
	@make -C libft fclean
	@make -C libft
	@echo "----------    Success    ----------"
	@echo ""
	@echo "---------- Compiling ASM ----------"
	@gcc -o $(NAME) $(FLAGS) $(SRCS) -L libft/ -lft -I ./include -I libft
	@echo "----------    Success    ----------"
	@echo "-----------------------------------"

a:
	@echo "---------- Compiling ASM ----------"
	@gcc -o $(NAME) $(FLAGS) $(SRCS) -L libft/ -lft -I ./include -I libft
	@echo "----------    Success    ----------"
	@echo ""
	@echo "----------      ASM      ----------"
	@./$(NAME)

v:
	@echo "---------- Compiling ASM ----------"
	@gcc -g -o $(NAME) $(FLAGS) $(SRCS) -L libft/ -lft -I ./include -I libft
	@echo "----------    Success    ----------"
	@echo ""
	@echo "----------      ASM      ----------"
	valgrind --tool=memcheck --leak-check=yes ./asm

clean:
	@rm $(NAME)
	@echo "----------  Removed ASM  ----------"

fclean:
	@make -C libft fclean
	@rm $(NAME)
	@echo "--------Full Clean Completed-------"

re: fclean all

norm:
	@clear
	@echo "----------   Norminette  ----------"
	@norminette $(SRC)
