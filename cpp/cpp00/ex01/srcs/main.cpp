#include "PhoneBook.hpp"

int main(void)
{
  std::string command;
  PhoneBook   phone_book = PhoneBook();

  while (true)
  {
    std::cout << "Please input the command, ADD, SEARCH, or EXIT" << std::endl;
    std::cin >> command;
    if (command.empty())
      break ;
    else if (command == "ADD")
    {
      if (!phone_book.addContact())
        break ;
    }
    else if (command == "SEARCH")
    {
      if (!phone_book.showBookContacts())
        break ;
    }
    else if (command == "EXIT")
        break ;
    command = "";
  }
  exit(0);
}
