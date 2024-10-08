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

  for (int i = 0; i < 4; i++) {
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
      if (rep == "inff" || rep == "+inff") {
        rep_float = std::numeric_limits<float>::infinity();
      } else if (rep == "-inff") {
        rep_float = -std::numeric_limits<float>::infinity();
      } else if (rep == "nanf") {
        rep_float = std::numeric_limits<float>::quiet_NaN();
      } else {
        if (!rep.empty() && rep[rep.size() - 1] == 'f') {
          rep.resize(rep.size() - 1);
        } else {
          continue ;
        }
        ss.str(rep);
        ss >> rep_float;
        rep.push_back('f');
        if (ss.fail() || !ss.eof())
          continue ;
      }
      rep_char = static_cast<unsigned char>(rep_float);
      rep_int = static_cast<int>(rep_float);
      rep_double = static_cast<double>(rep_float);
      break ;
    }
    else if (i == 2) {
      if (rep == "inf" || rep == "+inf") {
        rep_double = std::numeric_limits<double>::infinity();
      } else if (rep == "-inf") {
        rep_double = -std::numeric_limits<double>::infinity();
      } else if (rep == "nan") {
        rep_double = std::numeric_limits<double>::quiet_NaN();
      } else {
        ss.str(rep);
        ss >> rep_double;
        if (ss.fail() || !ss.eof())
          continue ;
      }
      rep_char = static_cast<unsigned char>(rep_double);
      rep_int = static_cast<int>(rep_double);
      rep_float = static_cast<float>(rep_double);
      break ;
    }
    else {
      std::cout << "Conversion is impossible for the Input" << std::endl;
      return ;
    }
  }
  std::cout << "char: ";
  if (!std::isfinite(rep_float))
    std::cout << "impossible" << std::endl;
  else if (std::isprint(rep_char))
    std::cout << "\'" << rep_char << "\'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
  std::cout << "int: ";
  if (!std::isfinite(rep_float))
    std::cout << "impossible" << std::endl;
  else
    std::cout << rep_int << std::endl;
  if (std::floor(rep_double) == rep_double)
    std::cout << std::fixed << std::setprecision(1);
  std::cout << "float: " << rep_float << "f" << std::endl;
  std::cout << "double: " << rep_double  << std::endl;
}
