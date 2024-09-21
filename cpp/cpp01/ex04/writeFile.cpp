#include "FileController.hpp"

int FileController::writeFile() {
  std::ofstream outfile(_filename_replace.c_str());

  if (!outfile.is_open()) {
    std::cerr << "Could not open " << _filename_replace << std::endl;
    return -1;
  }
  outfile << _write_buffer.str();
  outfile.close();
  return (0);
}
