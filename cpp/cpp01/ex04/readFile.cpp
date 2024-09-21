#include "FileController.hpp"

int FileController::readFile()
{
  std::ifstream infile(_filename.c_str());

  if (!infile.is_open()) {
    std::cerr << "Could not open " << _filename << std::endl;
    return -1;
  }
  this->_read_buffer << infile.rdbuf();
  infile.close();
  return 0;
}
