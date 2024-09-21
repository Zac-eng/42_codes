#include <string>
#include <iostream>
#include <locale>

void put_capital_str(std::string str);

int main(int argc, char *argv[])
{
  if (argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  else
  {
    for (int i = 1; i < argc; i++)
      put_capital_str(argv[i]);
    std::cout << std::endl;
  }
  return 0;
}

void put_capital_str(std::string str)
{
  int index = 0;
  std::locale l = std::locale::classic();
  while (str[index])
  {
    std::cout << std::toupper(str[index], l);
    index++;
  }
}
