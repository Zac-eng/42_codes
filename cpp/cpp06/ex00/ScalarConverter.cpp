#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& object) {
  *this = object;
}

ScalarConverter& ScalarConverter::operator = (const ScalarConverter& object) {
  (void)object;
  return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string rep) {
  try {
    if (isInt(rep))
      return printInt(std::stoi(rep));
  } catch (const std::invalid_argument& e) {
  } catch (const std::out_of_range& e) {
    std::cout << "the input is out of range" << std::endl;
    return ;
  }
  try {
    if (isFloat(rep))
      printFloat(std::stof(rep));
    else if (isDouble(rep))
      printDouble(std::stod(rep));
  } catch (const std::invalid_argument& e) {
    std::cout << "the input cannot be parsed as int, double, or float." << std::endl;
  } catch (const std::out_of_range& e) {
    std::cout << "the input is out of range" << std::endl;
  }
}

bool ScalarConverter::isInt(std::string rep) {
  std::size_t pos;
  std::stoi(rep, &pos);
  return pos == rep.length();
}

bool ScalarConverter::isFloat(std::string rep) {
  std::size_t pos;
  std::stof(rep, &pos);
  return pos == rep.length() - 1 && rep.back() == 'f';
}

bool ScalarConverter::isDouble(std::string rep) {
  std::size_t pos;
  std::stod(rep, &pos);
  return pos == rep.length();
}

void ScalarConverter::printInt(int input) {
  std::cout << "char: ";
  if (std::isprint(static_cast<unsigned char>(input)))
    std::cout << "\'" << static_cast<unsigned char>(input) << "\'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
  std::cout << "int: " << input << std::endl;
  std::cout << "float: " << static_cast<float>(input) << "f" << std::endl;
  std::cout << "double: " << static_cast<double>(input) << std::endl;
}

void ScalarConverter::printFloat(float input) {
  std::cout << "char: ";
  if (std::isprint(static_cast<unsigned char>(input)))
    std::cout << "\'" << static_cast<unsigned char>(input) << "\'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(input) << std::endl;
  std::cout << "float: " << input << "f" << std::endl;
  std::cout << "double: " << static_cast<double>(input) << std::endl;
}

void ScalarConverter::printDouble(double input) {
  std::cout << "char: ";
  if (std::isprint(static_cast<unsigned char>(input)))
    std::cout << "\'" << static_cast<unsigned char>(input) << "\'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(input) << std::endl;
  std::cout << "float: " << static_cast<float>(input) << "f" << std::endl;
  std::cout << "double: " << input << std::endl;
}
