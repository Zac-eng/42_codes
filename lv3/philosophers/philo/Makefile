# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmiyazak <hmiyazak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 14:47:24 by hmiyazak          #+#    #+#              #
#    Updated: 2024/05/07 18:00:11 by hmiyazak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
# CFLAGS += -g -fsanitize=thread
RM = rm -rf
SRCS = 	main.c\
		philo.c\
		actions.c\
		mutex_ops.c\
		create_table.c\
		monitor.c\
		utils/pos_atoi.c\
		utils/print_action.c\
		utils/time_ms.c\
		utils/wait_action.c\
		shared_handlers/change_shared.c\
		shared_handlers/get_shared.c
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re set
