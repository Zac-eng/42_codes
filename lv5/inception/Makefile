NAME=inception
COMPOSE_FILE=./srcs/docker-compose.yml
COMPOSE=docker-compose -f $(COMPOSE_FILE)

all: $(NAME)

$(NAME):
	$(COMPOSE) up -d

clean:
	$(COMPOSE) down

fclean:
	$(COMPOSE) down --rmi all

re: fclean all
