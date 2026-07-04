#include "identifier.hpp"

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "The object is of type A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "The object is of type B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "The object is of type C" << std::endl;
    } else {
        std::cout << "unexpected pointer detected... it was not A, B, or C." << std::endl;
    }
}

void identify(Base& p) {
  Base& casted = p;
  try {
    casted = dynamic_cast<A&>(p);
    std::cout << "the pointer is A's one" << std::endl;
    return ;
  } catch (...) {}
  try {
    casted = dynamic_cast<B&>(p);
    std::cout << "the pointer is B's one" << std::endl;
    return ;
  } catch (...) {}
  try {
    casted = dynamic_cast<C&>(p);
    std::cout << "the pointer is C's one" << std::endl;
    return ;
  } catch (...) {}
  (void)casted;
  std::cout << "unexpected pointer detected... it was not A, B, or C." << std::endl;
}
