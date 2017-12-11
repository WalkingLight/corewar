# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpauwels <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/14 14:46:37 by cpauwels          #+#    #+#              #
#    Updated: 2017/10/01 07:28:09 by cpauwels         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NONE = \x1b[0m
OK = \x1b[32;01m
WARN = \x1b[33;01m

BIN_ASM = asm_src/asm
BIN_COREWAR = vm_src/corewar

all:
	@echo "$(OK)----------    Make Libft   ----------$(NONE)\n"
	@make -C libft
	@make -C asm_src
	@make -C vm_src
	@echo "\n$(OK)----------     Success     ----------$(NONE)\n"
	@cp $(BIN_ASM) .
	@cp $(BIN_COREWAR) .

norm:
	@echo "$(OK)----------Norminette ASM----------$(NONE)"
	norminette asm_src/*.c
	@echo "$(OK)----------Norminette  VM----------$(NONE)"
	norminette vm_src/includes/*.c
	norminette vm_src/srcs/*.c
	norminette vm_src/srcs/operations/*.c

clean:
	@echo "$(WARN)----------     Clean       ----------$(NONE)"
	@make clean -C libft
	@make clean -C asm_src
	@make clean -C vm_src

fclean:
	@echo "$(WARN)----------     FClean      ----------$(NONE)"
	@make fclean -C libft
	@make fclean -C asm_src
	@make fclean -C vm_src
	@echo "$(WARN)--------Removing  executables--------$(NONE)"
	@rm asm
	@echo "Removed ./asm"
	@rm corewar
	@echo "Removed ./corewar"
	@rm *.cor
	@echo "Removed *.cor warriors\n"

re: fclean all
