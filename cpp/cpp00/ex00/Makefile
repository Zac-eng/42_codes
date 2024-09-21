NAME=megaphone
CPP=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
SRCS= ./megaphone.cpp
OBJS= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
