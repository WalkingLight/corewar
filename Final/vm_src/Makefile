# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/01 15:51:13 by rheukelm          #+#    #+#              #
#    Updated: 2017/10/01 15:51:15 by rheukelm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

SRCS =	srcs/champ_to_core.c srcs/check_params.c srcs/core_data.c \
		srcs/cycles.c srcs/data_var.c srcs/data_var_pc.c srcs/endian.c \
		srcs/exit_prog.c srcs/game_loop.c srcs/hex.c srcs/htoi.c \
		srcs/init_arena.c srcs/init_env.c srcs/init_var.c srcs/main.c \
		srcs/op.c srcs/pc.c srcs/print_arena.c srcs/process.c \
		srcs/process_init.c srcs/read_champ_data.c srcs/reg_data.c \
		srcs/run_exec_proc.c
OPER =	srcs/operations/add.c srcs/operations/aff.c srcs/operations/and.c \
		srcs/operations/fork.c srcs/operations/ft_valid_type.c \
		srcs/operations/ld.c srcs/operations/ldi.c srcs/operations/lfork.c \
		srcs/operations/live.c srcs/operations/lld.c srcs/operations/lldi.c \
		srcs/operations/or.c srcs/operations/st.c srcs/operations/sti.c \
		srcs/operations/sub.c srcs/operations/valid_reg.c \
		srcs/operations/xor.c srcs/operations/zjump.c

FLAGS = -Wall -Werror -Wextra -iquoteincludes

NONE = \x1b[0m
OK = \x1b[32;01m
WARN = \x1b[33;01m

all: $(NAME)

$(NAME):
	@echo "$(OK)----------   Compile VM    ----------$(NONE)"
	@gcc -o $(NAME) $(SRCS) $(OPER) ../libft/libft.a -iquoteincludes $(FLAGS)
	@echo "$(OK)----------     Success     ----------$(NONE)\n"

clean:
	@echo "$(WARN)----------    Clean VM     ----------$(NONE)"
	@rm -f $(NAME)
	@echo "Removed ./corewar"
	@echo "$(WARN)----------     Success     ----------$(NONE)\n"

fclean:
	@echo "$(WARN)----------    FClean VM    ----------$(NONE)"
	@rm -f $(NAME)
	@echo "Removed ./corewar"
	@echo "$(WARN)----------     Success     ----------$(NONE)\n"

re: fclean all
