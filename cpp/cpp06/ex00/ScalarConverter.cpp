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
  Representations reps;

  for (int i = 0; i < 3; i++) {
    ss.clear();
    ss.str(rep);
    std::cout << i << std::endl;
    if (i == 0) {
      ss >> reps.i;
      if (!ss.fail() && ss.eof()) {
        reps.c = static_cast<unsigned char>(reps.i);
        reps.f = static_cast<float>(reps.i);
        reps.d = static_cast<double>(reps.i);
        break ;
      }
    }
    else if (i == 1) {
      ss >> reps.f;
      if (!ss.fail() && ss.eof()) {
        reps.c = static_cast<unsigned char>(reps.f);
        reps.i = static_cast<int>(reps.f);
        reps.d = static_cast<double>(reps.f);
        break ;
      }
    }
    else if (i == 2) {
      ss >> reps.d;
      if (!ss.fail() && ss.eof()) {
        reps.c = static_cast<unsigned char>(reps.d);
        reps.i = static_cast<int>(reps.d);
        reps.f = static_cast<float>(reps.d);
        break ;
      }
    }
    // ss.clear();
  }
  if (ss.fail()) {
    std::cout << "Conversion is impossible for the Input" << std::endl;
  }
  std::cout << "char: ";
  if (std::isprint(reps.c))
    std::cout << "\'" << reps.c << "\'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
  std::cout << "int: " << reps.i << std::endl;
  std::cout << "float: " << reps.f << "f" << std::endl;
  std::cout << "double: " << reps.d << std::endl;
}
