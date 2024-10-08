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
  std::stringstream ss;
  char rep_char;
  int rep_int;
  float rep_float;
  double rep_double;

  for (int i = 0; i < 3; i++) {
    ss.clear();
    if (i == 0) {
      ss.str(rep);
      ss >> rep_int;
      if (!ss.fail() && ss.eof()) {
        rep_char = static_cast<unsigned char>(rep_int);
        rep_float = static_cast<float>(rep_int);
        rep_double = static_cast<double>(rep_int);
        break ;
      }
    }
    else if (i == 1) {
      if (!rep.empty() && rep.back() == 'f') {
        rep.pop_back();
      } else {
        continue ;
      }
      ss.str(rep);
      ss >> rep_float;
      if (!ss.fail() && ss.eof()) {
        rep_char = static_cast<unsigned char>(rep_float);
        rep_int = static_cast<int>(rep_float);
        rep_double = static_cast<double>(rep_float);
        break ;
      }
    }
    else if (i == 2) {
      ss.str(rep);
      ss >> rep_double;
      if (!ss.fail() && ss.eof()) {
        rep_char = static_cast<unsigned char>(rep_double);
        rep_int = static_cast<int>(rep_double);
        rep_float = static_cast<float>(rep_double);
        break ;
      }
    }
  }
  if (ss.fail() || !ss.eof()) {
    std::cout << "Conversion is impossible for the Input" << std::endl;
    return ;
  }
  std::cout << "char: ";
  if (std::isprint(rep_char))
    std::cout << "\'" << rep_char << "\'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
  std::cout << "int: " << rep_int << std::endl;
  std::cout << "float: " << rep_float << (rep_float == static_cast<float>(rep_int) ? ".0" : "") << "f" << std::endl;
  std::cout << "double: " << rep_double << (rep_float == static_cast<float>(rep_int) ? ".0" : "") << std::endl;
}
