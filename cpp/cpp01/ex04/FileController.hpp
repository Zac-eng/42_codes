#ifndef FILE_CONTROLLER_HPP
# define FILE_CONTROLLER_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <sstream>

class FileController
{
private:
  std::string _filename;
  std::string _filename_replace;
  std::string _replace_from;
  std::string _replace_to;
  std::stringstream _read_buffer;
  std::stringstream _write_buffer;

public:
  FileController(const std::string filename, const std::string from, const std::string to);
  ~FileController();
  int readFile();
  void replaceWords();
  int writeFile();
};

#endif
