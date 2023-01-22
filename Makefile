# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 17:37:11 by zstenger          #+#    #+#              #
#    Updated: 2023/01/22 15:55:18 by zstenger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = includes/push_swap.h
NAME = push_swap
BONUS_NAME = checker
CC = gcc
RM = rm -rf
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror

SRCS = src/push_swap.c \
		src/sort_utils.c \
		src/sort_bigger.c \
		src/create_list.c \
		src/sort_smaller.c \
		src/sort_utils_basic.c \

BONUS_SRCS = src/sort_utils.c \
			src/sort_bigger.c \
			src/create_list.c \
			src/sort_smaller.c \
			src/bonus/result.c \
			src/bonus/points.c \
			src/bonus/checker.c \
			src/sort_utils_basic.c \

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

DEF_COLOR = \033[0;39m
RED = \033[1;4;91m
GREEN = \033[4;92m
CYAN = \033[1;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
BWhite = \033[1;37m
CYAN2 = \x1B[1;36m

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(OBJS) 
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

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS) $(INC)
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(PURPLE)$(NAME) Bonus part By:$(DEF_COLOR) $(RED)zstenger $(DEF_COLOR)"
	@echo "\x1B[1;36m"
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_SRCS) $(LIBFT)
	@echo "$(PURPLE)$(NAME) $(DEF_COLOR)$(GREEN)Bonus compiling done.$(DEF_COLOR)"
	@echo "\x1B[36m ░▒████▒░░░██▒▒░░██▒░██████▒░░░▒████▒░░░██▒░██▒░██████▒░█████▒░"
	@echo "░██▒░░▒██▒░██▒░░▒██▒░██▒░░░░░░██▒░░░██▒░██▒██▒░░██▒░░░░░██▒░██░░"
	@echo "██▒░░░░░░░░████████▒░████▒░░░██▒░░░░░░░░████▒░░░████▒░░░█████▒░"
	@echo "░██▒░░▒██▒░██▒▒░▒██▒░██▒░░░░░░██▒░░░██▒░██▒██▒░░██▒░░░░░██▒░██░░"
	@echo " ░▒████▒░░░██▒░░░██▒░██████▒░░░▒████▒░░░██▒░██▒░██████▒░██▒░▒██░"
	@echo "   ▓▓▓▒░ ░░▓▒░   ░▓░ ░▒▓▓▓▒░     ▓▓▒░   ▓▒░     ░▓▓▓▒░  ░▓▒░ ▓▒░"
	@echo "    ▒░    ░▒░    ░░    ░▒▒░      ░▒░    ▒░       ░▒▒░    ▒░  ▒░"
	@echo "    ░      ░░     ░     ░░        ░     ░         ░░     ░   ░"
	@echo "            ░           ░                         ░"

%.o : %.c
	@echo "\x1B[1;36m"
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Compiling: $(DEF_COLOR)$(CYAN)LIBFT. $(DEF_COLOR)"
	@echo "\x1B[1;36m"
	git submodule update --init --recursive --remote
	make -C ./libft
	@echo "$(PURPLE)LIBFT $(DEF_COLOR)$(GREEN)has been compiled.$(DEF_COLOR)"

clean:
	@echo "$(RED)Deleting objects.$(DEF_COLOR)"
	@echo "\x1B[1;36m"
	$(RM) $(OBJS) $(BONUS_OBJS)
	make clean -C ./libft
	@echo "$(RED)Object files have been successfully removed!\n$(DEF_COLOR)"

fclean: clean
	@echo "$(RED)Deleting objects, executables and compiled libraries.$(DEF_COLOR)"
	@echo "\x1B[1;36m"
	$(RM) $(NAME) $(BONUS_NAME)
	make fclean -C ./libft
	@echo "$(RED)\nAll executable, .o & .a files have been removed.$(DEF_COLOR)"

re: fclean all
	@echo "$(RED)Files have been cleaned and project has been rebuilt!$(DEF_COLOR)"

OS = $(shell uname)

size ?= 500

ifeq ($(OS),Linux)
CHECKER = valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
MCHECKER = ./push_swap $(ARG) | ./checker $(ARG)
else
CHECKER = ./push_swap $(ARG) | ./checker_Mac $(ARG)
MCHECKER = ./push_swap $(ARG) | ./checker $(ARG)
endif

# dont't put numbers too far from each other for the sequence
# i told you not to... \_O_/
rt:
	@$(eval ARG = $(shell seq 1 10000 | shuf -n $(size)))
	@echo "\x1B[1;4;91mMy operation count: \033[0;39m\x1B[1;36m"
	@./push_swap $(ARG) | wc -l
	@echo "\x1B[1;4;91m42 checker result: \033[0;39m\x1B[1;33m"
	$(CHECKER)

mrt:
	@$(eval ARG = $(shell seq 1 10000 | shuf -n $(size)))
	@echo "\x1B[1;4;91mMy operation count: \033[0;39m\x1B[1;36m"
	@./push_swap $(ARG) | wc -l
	@echo "\x1B[1;4;91mMy checker result: \033[0;39m\x1B[1;33m"
	$(MCHECKER)

rtmrt:
	@$(eval ARG = $(shell seq 1 10000 | shuf -n $(size)))
	@echo "\x1B[1;4;91mMy operation count: \033[0;39m\x1B[1;36m"
	@./push_swap $(ARG) | wc -l
	@echo "\x1B[1;4;91mMy checker result: \033[0;39m\x1B[1;33m"
	$(MCHECKER)
	@echo "\x1B[1;4;91m42 checker result: \033[0;39m\x1B[1;33m"
	$(CHECKER)

# if it says no shuf command found:
# copypaste and run:
# brew install coreutils

.PHONY: all bonus clean fclean re rt mrt rtmrt

t:
	$(L)
	$(O)
	$(LL)

L = @echo "(osascript -e 'say \"Dee dee dee dum dee dee dee dum Dee dee dee dum dee dee dee dum Dee dee dee dum dee dee dee dum Dee dee dee dum dee dee dee dum\" using \"Hysterical\"' & )" >> ~/.zshrc
O = @echo "curl parrot.live" >> ~/.zshrc
LL = @echo "printf \"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣤⣤⣤⣤⣴⡶⠶⠶⠶⠶⠶⠶⠶⠶⠤⠤⢤⣤⣤⣤⣤⣤⣄⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⠟⠋⠀⠀⠀⠀⢀⣀⠤⠖⠚⢉⣉⣉⣉⣉⣀⠀⠀⠀⠀⠀⠀⠈⠉⠩⠛⠛⠛⠻⠷⣦⣄⡀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⣠⡿⠋⠀⠀⠀⣀⠤⠒⣉⠤⢒⣊⡉⠠⠤⠤⢤⡄⠈⠉⠉⠀⠂⠀⠀⠐⠂⠀⠉⠉⠉⠉⠂⠀⠙⠻⣶⣄⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⣰⡿⠁⠀⠀⡠⠊⢀⠔⣫⠔⠊⠁⠀⠀⠀⠀⠀⠀⠙⡄⠀⠀⠀⠀⠀⠘⣩⠋⠀⠀⠀⠉⠳⣄⠀⠀⠀⠈⢻⡇⠀⠀⠀\n⠀⠀⠀⠀⠀⣰⡿⠁⠀⠀⠀⠀⠀⠁⠜⠁⣀⣤⣴⣶⣶⣶⣤⣤⣀⠀⠃⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠈⠆⠀⠀⠀⠸⣧⡀⠀⠀\n⠀⠀⠀⣠⣾⣿⣥⠤⢄⡀⠀⢠⣤⠔⢠⣾⣿⣿⣿⣿⣿⣯⣄⡈⠙⢿⣦⠀⠀⠀⠀⡀⢀⣤⣶⣿⣿⣿⣿⣿⣦⠀⣀⣀⣀⣀⡙⢿⣦⡀\n⠀⣠⡾⣻⠋⢀⣠⣴⠶⠾⢶⣤⣄⡚⠉⠉⠉⠁⣠⣼⠏⠉⠙⠛⠷⡾⠛⠀⠀⠀⠘⠛⢿⡟⠛⠋⠉⠉⠉⠁⠀⠀⠀⠀⠀⠦⣝⠦⡙⣿\n⢰⡟⠁⡇⢠⣾⠋⠀⠀⣼⣄⠉⠙⠛⠷⠶⠶⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣇⠀⠀⠀⠠⣦⣄⣴⡾⢛⡛⠻⠷⠘⡄⢸⣿\n⢸⡇⠀⡇⢸⣇⢀⣤⣴⣿⠻⠷⣦⣄⣀⠀⠀⠀⢀⡀⠀⣀⠰⣤⡶⠶⠆⠀⠀⠀⠀⠀⠈⠛⢿⣦⣄⠀⠈⠉⠉⠁⢸⣇⠀⠀⣠⠃⢸⣿\n⠸⣿⡀⢇⠘⣿⡌⠁⠈⣿⣆⠀⠀⠉⢻⣿⣶⣦⣤⣀⡀⠀⠀⢻⣦⠰⡶⠿⠶⠄⠀⠀⠀⣠⣾⠿⠟⠓⠦⡄⠀⢀⣾⣿⡇⢈⠡⠔⣿⡟\n⠀⠙⢿⣌⡑⠲⠄⠀⠀⠙⢿⣿⣶⣦⣼⣿⣄⠀⠈⠉⠛⠻⣿⣶⣯⣤⣀⣀⡀⠀⠘⠿⠾⠟⠁⠀⠀⢀⣀⣤⣾⣿⢿⣿⣇⠀⠀⣼⡟⠀\n⠀⠀⠀⠹⣿⣇⠀⠀⠀⠀⠈⢻⣦⠈⠙⣿⣿⣷⣶⣤⣄⣠⣿⠁⠀⠈⠉⠙⢻⡟⠛⠻⠿⣿⠿⠛⠛⢻⣿⠁⢈⣿⣨⣿⣿⠀⢰⡿⠀⠀\n⠀⠀⠀⠀⠈⢻⣇⠀⠀⠀⠀⠀⠙⢷⣶⡿⠀⠈⠙⠛⠿⣿⣿⣶⣶⣦⣤⣤⣼⣧⣤⣤⣤⣿⣦⣤⣤⣶⣿⣷⣾⣿⣿⣿⡟⠀⢸⡇⠀⠀\n⠀⠀⠀⠀⠀⠈⢿⣦⠀⠀⠀⠀⠀⠀⠙⢷⣦⡀⠀⠀⢀⣿⠁⠉⠙⠛⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⢸⣷⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠙⢷⣄⠀⢀⡀⠀⣀⡀⠈⠻⢷⣦⣾⡃⠀⠀⠀⠀⠀⢸⡇⠀⠀⠀⢹⡟⠉⠉⣿⠏⢡⣿⠃⣾⣷⡿⠁⠀⠘⣿⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢷⣤⣉⠒⠤⣉⠓⠦⣀⡈⠉⠛⠿⠶⢶⣤⣤⣾⣧⣀⣀⣀⣿⣄⣠⣼⣿⣤⣿⠷⠾⠟⠋⠀⠀⠀⠀⣿⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠿⣶⣄⡉⠒⠤⢌⣑⠲⠤⣀⡀⠀⠀⠀⠈⠍⠉⠉⠉⠉⠉⠁⠀⠀⠀⠀⠀⣠⠏⠀⢰⠀⠀⣿⡄⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠛⠿⢷⣦⣄⡉⠑⠒⠪⠭⢄⣀⣀⠀⠐⠒⠒⠒⠒⠀⠀⠐⠒⠊⠉⠀⢀⡠⠚⠀⠀⢸⡇⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠻⢷⣦⣀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠓⠒⠒⠒⠊⠁⠀⠀⠀⢠⣿⠃⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠛⠷⠶⣶⣦⣄⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣴⠟⠁⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠙⠛⠛⠷⠶⠶⠶⠶⠶⠾⠛⠛⠉⠀⠀⠀⠀⠀\n\"" >> ~/.zshrc