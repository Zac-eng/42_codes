NAME=phonebook
CPP=c++
CPPFLAGS=-Wall -Wextra -Werror -std=c++98
SRCS= ./srcs/main.cpp ./srcs/Contact.cpp ./srcs/PhoneBook.cpp ./srcs/addContact.cpp ./srcs/showBookContacts.cpp ./srcs/showContact.cpp
OBJS=$(SRCS:.cpp=.o)
INCLUDES=includes

%.o: %.cpp
	$(CPP) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
