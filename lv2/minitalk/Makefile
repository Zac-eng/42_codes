NAME = minitalk
CLIENT = client
SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENTSRCS = ./clientdir
SERVERSRCS = ./serverdir
PRINTFDIR = ./ft_printf
PRINTF = libftprintf.a
RM = rm -rf

#+++++general+++++

all: $(NAME)

$(NAME): $(PRINTF) $(CLIENT) $(SERVER)

$(CLIENT):
	make -C $(CLIENTSRCS) all
	mv $(CLIENTSRCS)/$(CLIENT) .
$(SERVER): $(PRINTF)
	make -C $(SERVERSRCS) all
	mv $(SERVERSRCS)/$(SERVER) .

clean:
	make -C $(PRINTFDIR) clean
	make -C $(CLIENTSRCS) clean
	make -C $(SERVERSRCS) clean
fclean: clean
	$(RM) ./$(PRINTF) ./$(CLIENT) ./$(SERVER)
	make -C $(PRINTFDIR) fclean
	make -C $(CLIENTSRCS) fclean
	make -C $(SERVERSRCS) fclean
re: fclean all

#+++++ft_printf+++++

$(PRINTF):
	make -C $(PRINTFDIR) all
	mv ./ft_printf/libftprintf.a .

#++++++++++++++++

.PHONY: all clean fclean re
