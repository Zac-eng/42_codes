# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/03 12:17:42 by hmiyazak          #+#    #+#              #
#    Updated: 2023/10/31 22:43:01 by hmiyazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c afew_nodes_ops.c many_nodes_ops.c input_handlers/compress_list.c \
		input_handlers/create_input_list.c input_handlers/create_stack.c\
		input_handlers/utils.c stack_handlers/basic_ops.c stack_handlers/push.c\
		stack_handlers/reverse_rotate.c stack_handlers/swap.c stack_handlers/rotate.c
OBJS = $(SRCS:.c=.o)
RM = rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
