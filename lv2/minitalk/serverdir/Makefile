NAME = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c generate_char.c ../libftprintf.a
INCLUDE = -I ../printf
RM = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) -o $@

clean:

fclean: clean
	$(RM) $(NAME)

re: fclean all

PHONY: all clean fclean re