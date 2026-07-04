#include "ScalarConverter.hpp"

int main(int argc, char* argv[]) {
  ScalarConverter converter;

  if (argc != 2)
    return 1;
  converter.convert(argv[1]);
}
