NAME = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c char_handling.c read_pid.c ../libftprintf.a
INCLUDE = -I ../ft_printf
RM = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) -o $@

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re