NAME=account
CPP=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
SRCS= ./tests.cpp ./Account.cpp
OBJS= $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
