#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cctype>
# include <stdexcept>

union Representations {
  char c;
  int i;
  float f;
  double d;
};

class ScalarConverter {

public:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter& object);
  ScalarConverter& operator = (const ScalarConverter& object);
  ~ScalarConverter();
  static void convert(std::string rep);

};

#endif