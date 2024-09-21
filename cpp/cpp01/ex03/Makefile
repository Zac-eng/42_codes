NAME=unnecessarywar
CPP=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
SRCS= main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJS= $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
