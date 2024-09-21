#include "FileController.hpp"

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cerr << "INVALID ARGS: arguments should be <filenmame> str_from str_to" << std::endl;
    return (0);
  }
  std::string filename = argv[1];
  std::string str_from = argv[2];
  std::string str_to = argv[3];
  FileController  fileController(filename, str_from, str_to);

  if (fileController.readFile() != 0)
    return (1);
  fileController.replaceWords();
  if (fileController.writeFile() != 0)
    return (1);
  return (0);
}
