NAME=convert
CXX=c++
CXXFLAGS=-Wall -Wextra -Werror -std=c++98
SRCS = $(shell find . -type f -name '*.cpp')
OBJS= $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all