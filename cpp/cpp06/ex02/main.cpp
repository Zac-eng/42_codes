#include "identifier.hpp"

int main(void) {
  Base* random_base = generate();
  if (!random_base) {
    std::cout << "error occurred creating Base instance" << std::endl;
    return 1;
  }
  B    b;

  identify(random_base);
  identify(*random_base);
  identify(&b);
  identify(b);
  delete random_base;
  return 0;
}
