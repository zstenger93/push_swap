# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 17:37:11 by zstenger          #+#    #+#              #
#    Updated: 2023/01/12 12:04:31 by zstenger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

file := random_string.txt
NAME = push_swap
CC = gcc
RM = rm -rf
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c \
		sort_smaller.c \
		sort_bigger.c \
		sort_utils.c \
		basic_utils.c \
		error.c \

OBJS = $(SRCS:.c=.o)

DEF_COLOR = \033[0;39m
RED = \033[1;91m
GREEN = \033[4;92m
CYAN = \033[1;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
BWhite = \033[1;37m

all: $(NAME)

$(NAME): $(LIBFT) colorit $(OBJS) 
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(PURPLE)$(NAME) Mandatory part By:$(DEF_COLOR) $(RED)zstenger $(DEF_COLOR)"
	@echo "\x1B[1;36m"
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)
	@echo "$(PURPLE)$(NAME) $(DEF_COLOR)$(GREEN)Compiling done.$(DEF_COLOR)"
	@echo "\x1B[36m ██▓███   █    ██   ██████  ██░ ██   ██████  █     █░ ▄▄▄       ██▓███      ░████████  ██████  ████████  █████  ███░  ██  ░██████     █████   ████▓░"
	@echo "▓██░  ██▒ ██  ▓██▒▒██    ▒ ▓██░ ██▒▒██    ▒ ▓█░ █ ░█░▒████▄    ▓██░  ██▒   ░▒ ░░▒███ ▒██▒░  ▒░  ░▒██▒░  ██▒░   ██░█░░██  ██▓▒ ▒▓██   ██▒░░   ██░ ░██"
	@echo "▓██░ ██▓▒▓██  ▒██░░ ▓██▄   ▒██▀▀██░░ ▓██▄   ▒█░ █ ░█ ▒██  ▀█▄  ▓██░ ██▓▒     ░▒███▓▒ ░ ▓██▄  ░ ░▒██▒░  ████   ██░█░░██  ██▓▒░▓█░    ████░░░ ██████▓"
	@echo "▒██▄█▓▒ ▒▓▓█  ░██░  ▒   ██▒░▓█ ░██   ▒   ██▒░█░ █ ░█ ░██▄▄▄▄██ ▒██▄█▓▒ ▒    ░▒███▓▒    ▒   ██ ░▒██▒░  ██▒░   ██░█░░██   ▒██▓▒▒▓██  ██▒░░░  ██▒░▒██░"
	@echo "▒██▒ ░  ░▒▒█████▓ ▒██████▒▒░▓█▒░██▓▒██████▒▒░░██▒██▓  ▓█   ▓██▒▒██▒ ░  ░   ░████████ ▒██████▒▒ ██▒░  ██████ ██░▓███▒░     ▒████░  ██████  ██▒░ ░▒██░"
	@echo "▒▓▒░ ░  ░░▒▓▒ ▒ ▒ ▒ ▒▓▒ ▒ ░ ▒ ░░▒░▒▒ ▒▓▒ ▒ ░░ ▓░▒ ▒   ▒▒   ▓▒█░▒▓▒░ ░  ░░  ░▒██▒    ░░▒ ▒▓▒ ▒ ░  ░   ░▓░▒ ▒ ▒ ░░▒░▒▒       ▒▓▒ ▒   ▓░▒ ▒  ▒▓░   ░▒▓░"
	@echo "░▒ ░     ░░▒░ ░ ░ ░ ░▒  ░ ░ ▒ ░▒░ ░░ ░▒  ░ ░  ▒ ░ ░    ▒   ▒▒ ░░▒ ░     ░░ ░▒▓▒     ░▒ ▒▓▒ ▒ ░   ░   ▒ ░ ░  ▒ ░▒░ ░░       ░▒  ░  ▒ ░ ░   ░░      ░░░"
	@echo "░░        ░░░ ░ ░ ░  ░  ░   ░  ░░ ░░  ░  ░    ░   ░    ░   ▒   ░░       ░ ░░ ░       ░ ░▒  ░ ░       ░   ░     ░           ░     ░░       ░       ░ ░"
	@echo "░           ░           ░   ░  ░  ░      ░      ░          ░  ░         ░ ░            ░     ░         ░                                           ░"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN)LIBFT. $(DEF_COLOR)"
	@echo "\x1B[1;36m"
	git submodule update --init --recursive --remote
	make -C ./libft
	@echo "$(PURPLE)LIBFT $(DEF_COLOR)$(GREEN)has been compiled.$(DEF_COLOR)"

clean:
	@echo "\x1B[1;36m"
	$(RM) $(OBJS)
	make clean -C ./libft
	@echo "$(RED)Object files have been successfully removed!$(DEF_COLOR)"

fclean: clean
	@echo "$(RED)Deleting objects.$(DEF_COLOR)"
	@echo "\x1B[1;36m"
	$(RM) $(NAME)
	make fclean -C ./libft
	@echo "$(RED)All .o & .a files have been removed.$(DEF_COLOR)"

re: fclean all
	@echo "$(RED)Files have been cleaned and project has been rebuilt!$(DEF_COLOR)"

colorit:
	@echo "\x1B[1;36m"

random_string.txt:
	touch $@

random_string:
	@if [ -f random_string.txt ]; then \
	  random_string="" ;\
	  generated_numbers=() ;\
	  for i in {1..100} ;\
	  do \
	  random_number=$$((RANDOM % 500)) ;\
	  for index in $${generated_numbers[*]} ;\
	  do \
		if [[ $$index -eq $$random_number ]]; then \
			random_number=$$((RANDOM % 500)) ;\
			break; \
		fi; \
	  done; \
	  generated_numbers+=($$random_number) ;\
	  random_string="$$random_string $$random_number" ;\
	done ;\
	echo "$$random_string" > random_string.txt ;\
	fi
test:random_string 
	ARG="$(shell cat ${file})"; ./$(NAME) $$ARG | wc -l
	ARG="$(shell cat ${file})"; ./$(NAME) $$ARG | ./checker_Mac $$ARG

.PHONY: all clean fclean re

# random_string="" ;\
# 	for i in {1..500} ;\
# 	do \
# 	  generated_numbers=() ;\
# 	  random_number=$$((RANDOM % 500)) ;\
# 	  for index in $${generated_numbers[*]} ;\
# 	  do \
# 		if [[ $$index -eq $$random_number ]]; then \
# 			random_number=$$((RANDOM % 500)) ;\
# 			break; \
# 		fi; \
# 	  done; \
# 	  generated_numbers+=($$random_number);\
# 	  random_string="$$random_string $$random_number" ;\
# 	done ;\
# 	echo "$$random_string" > random_string.txt ;\

# @if [ -f random_string.txt ]; then \
# 	  random_string="" ;\
# 	  generated_numbers=() ;\
# 	  for i in {1..100} ;\
# 	  do \
# 	    random_number=$$((RANDOM % 500)) ;\
# 	    while [[ ${generated_numbers[$$random_number]} -eq 1 ]] ;\
# 	    do \
# 	      random_number=$$((RANDOM % 500)) ;\
# 	    done ;\
# 	    generated_numbers[$$random_number]=1 ;\
# 	    random_string="$$random_string $$random_number" ;\
# 	  done ;\
# 	  echo "$$random_string" > random_string.txt ;\
# 	fi