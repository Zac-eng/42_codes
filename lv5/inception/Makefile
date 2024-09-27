NAME=inception

all: $(NAME)

$(NAME):
	@cd ./srcs
	docker-compose up -d
	@cd ..
	# echo "127.0.0.1 hmiyazak.42.fr" >> /etc/hosts
	# sudo dscacheutil -flushcache
	# sudo killall -HUP mDNSResponder

clean:
	@cd ./srcs
	docker-compose down
	@cd ..

fclean: clean

re: fclean all
