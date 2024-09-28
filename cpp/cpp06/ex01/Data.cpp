#include "Data.hpp"

Data::Data(void): _content("No content") {}

Data::Data(std::string input): _content(input) {}

Data& Data::operator = (const Data& object) {
  this->overwriteContent(object.readContent());
  return *this;
}

Data::~Data() {}

std::string Data::readContent() const {
  return this->_content;
}

void Data::overwriteContent(std::string input) {
  this->_content = input;
}

void Data::appendContent(std::string input) {
  this->_content.append(input);
}
