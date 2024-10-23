#include "Span.hpp"

Span::Span(void) {}

Span::Span(unsigned int n) {
  _capacity = n;
}

Span::~Span() {}

Span::Span(const Span& object) {
  *this = object;
}

Span& Span::operator = (const Span& object) {
  this->_capacity = object._capacity;
  for (std::size_t i = 0; i < object._contents.size(); i++) {
    this->addNumber(object._contents[i]);
  }
  return *this;
}

void Span::addNumber(int to_add) {
  if (_contents.size() >= _capacity)
    throw std::exception();
  if (_contents.size() >= 1)
    _spans.push_back(std::abs(to_add - _contents.back()));
  _contents.push_back(to_add);
}

int Span::shortestSpan(void) {
  if (_contents.size() <= 1)
    throw std::exception();
  return *std::min_element(_spans.begin(), _spans.end());
}

int Span::longestSpan(void) {
  if (_contents.size() <= 1)
    throw std::exception();
  return *std::max_element(_spans.begin(), _spans.end());
}
