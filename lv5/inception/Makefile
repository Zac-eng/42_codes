NAME=inception
COMPOSE_FILE=./srcs/docker-compose.yml
COMPOSE=docker compose -f $(COMPOSE_FILE)
RM=rm -rf

all: $(NAME)

$(NAME):
	$(COMPOSE) up -d

clean:
	$(COMPOSE) down

fclean:
	$(COMPOSE) down --volumes --rmi all
	$(RM) ~/data

log:
	$(COMPOSE) logs

re: fclean all
