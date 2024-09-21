#include "FileController.hpp"

FileController::FileController(const std::string filename, const std::string from, const std::string to)
{
  this->_filename = filename;
  this->_filename_replace = this->_filename + ".replace";
  this->_replace_from = from;
  this->_replace_to = to;
}

FileController::~FileController() {}
