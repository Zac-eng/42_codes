#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <stdexcept>

class ScalarConverter {

private:
  static bool isInt(std::string rep);
  static bool isFloat(std::string rep);
  static bool isDouble(std::string rep);
  static void printInt(int input);
  static void printFloat(float input);
  static void printDouble(double input);

public:
  ScalarConverter(void);
  ScalarConverter(const ScalarConverter& object);
  ScalarConverter& operator = (const ScalarConverter& object);
  ~ScalarConverter();
  static void convert(std::string rep);

};

#endif
