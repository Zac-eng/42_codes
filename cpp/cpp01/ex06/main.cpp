#include "Harl.hpp"

int main(int argc, char *argv[]) {
  Harl      harl;
  HarlLevel level;

  if (argc != 2) {
    std::cerr << "INVALID NUMBER OF ARGUMENTS TO FILTER" << std::endl;
    return 0;
  }
  std::string harl_level(argv[1]);
  if (harl_level == "DEBUG") {
    level = DEBUG;
  } else if (harl_level == "INFO") {
    level = INFO;
  } else if (harl_level == "WARNING") {
    level = WARNING;
  } else if (harl_level == "ERROR") {
    level = ERROR;
  } else {
    level = OTHERS;
  }
  harl.complain(level);
  return 0;
}
