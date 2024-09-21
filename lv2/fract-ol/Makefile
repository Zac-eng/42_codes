NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = main.c julia.c mandelbrot.c common_function.c control_window.c ./utils/ft_atof.c ./utils/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
PRINTFDIR = ./ft_printf
PRINTF = libftprintf.a
RM = rm -rf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#+++++general+++++

all: $(NAME)

$(NAME): $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS) $(PRINTF) -o $@

$(PRINTF):
	make -C $(PRINTFDIR) all
	mv $(PRINTFDIR)/$(PRINTF) .

clean:
	$(RM) $(OBJS)
	make -C $(PRINTFDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(PRINTF)
	make -C $(PRINTFDIR) fclean

re: fclean all

#++++++++++++++++

.PHONY: all clean fclean re
