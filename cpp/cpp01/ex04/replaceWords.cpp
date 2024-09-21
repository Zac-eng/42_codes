#include "FileController.hpp"

void  FileController::replaceWords() {
  size_t  position = 0;
  std::string input = _read_buffer.str();

  while (position != std::string::npos) {
    size_t  replace_pos = input.find(_replace_from, position);
    if (replace_pos != std::string::npos) {
      _write_buffer << input.substr(position, replace_pos - position);
      _write_buffer << _replace_to;
      position = replace_pos + _replace_from.length();
    } else {
      _write_buffer << input.substr(position);
      break ;
    }
  }
}
