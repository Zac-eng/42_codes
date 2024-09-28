#include "identifier.hpp"
#include <thread>
#include <chrono>

int main(void) {
  Base* random_base = generate();
  if (!random_base) {
    std::cout << "error occurred creating Base instance" << std::endl;
    return 1;
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
  Base* random_another = generate();
  if (!random_base) {
    std::cout << "error occurred creating Base instance" << std::endl;
    delete random_base;
    return 1;
  }
  B    b;

  identify(random_base);
  identify(*random_another);
  identify(&b);
  identify(b);
  delete random_base;
  delete random_another;
  return 0;
}