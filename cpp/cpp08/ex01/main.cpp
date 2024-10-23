#include "Span.hpp"
#include <iostream>

int main(void) {
  Span copy(5);
  try {
    copy.longestSpan();
  } catch (std::exception& e) {
    std::cout << "exception detected" << std::endl;
  }
  {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    copy = sp;
  }
  try {
    copy.addNumber(10);
  } catch (std::exception& e) {
    std::cout << "exception detected" << std::endl;
  }
  std::cout << copy.shortestSpan() << std::endl;
  std::cout << copy.longestSpan() << std::endl;
}
