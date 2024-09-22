NAME=inception

all: $(NAME)

$(NAME):
	@cd ./srcs
	docker-compose up -d
	@cd ..

clean:
	@cd ./srcs
	docker-compose down
	@cd ..

fclean: clean

re: fclean all
