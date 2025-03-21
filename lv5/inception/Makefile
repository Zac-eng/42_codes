NAME=inception
COMPOSE_FILE=./srcs/docker-compose.yml
COMPOSE=docker compose -f $(COMPOSE_FILE)
VOLUME_DIR=/home/hmiyazak/data
WP_DIR=$(VOLUME_DIR)/wordpress_files
SQL_DIR=$(VOLUME_DIR)/mysql

all: $(NAME)

$(NAME):
	mkdir -p $(WP_DIR)
	mkdir -p $(SQL_DIR)
	$(COMPOSE) up -d

clean:
	$(COMPOSE) down

fclean:
	sudo rm -rf $(VOLUME_DIR)
	$(COMPOSE) down --volumes --rmi all

stop:
	$(COMPOSE) stop

start:
	$(COMPOSE) start

log:
	$(COMPOSE) logs

re: fclean all
