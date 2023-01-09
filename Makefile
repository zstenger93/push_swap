# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 17:37:11 by zstenger          #+#    #+#              #
#    Updated: 2023/01/09 19:54:04 by zstenger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -rf
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c sort_smaller.c basic_utils.c operations/sa.c operations/sb.c \
		operations/ss.c operations/pa.c operations/pb.c operations/ra.c \
		operations/rb.c operations/rra.c operations/rrb.c operations/rrr.c \
		operations/rr.c create_stack_a.c sort_utils.c error.c chunk_operations.c \
		sort_bigger.c stack_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBFT)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	git submodule update --init --recursive --remote
	make -C ./libft

clean:
	$(RM) $(OBJS)
	@echo "$(CYAN)Object files are successfully removed!$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(CYAN)The .a file has been removed!$(DEF_COLOR)"

re: fclean all
	@echo "$(RED)Files have been cleaned and project has been rebuilt!$(DEF_COLOR)"

.PHONY: all clean fclean re