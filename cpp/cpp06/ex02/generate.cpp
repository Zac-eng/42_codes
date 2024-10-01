#include "identifier.hpp"

static int generate_random_mod3(void);

Base* generate(void) {
  int random = generate_random_mod3();
  if (random == 0) {
    return new A();
  } else if (random == 1) {
    return new B();
  } else if (random == 2) {
    return new C();
  } else {
    return NULL;
  }
}

static int generate_random_mod3(void) {
  std::srand(static_cast<unsigned int>(std::time(0)));
  std::srand(static_cast<unsigned int>(std::rand()));
  int randomNumber = std::rand();
  return randomNumber % 3;
}
