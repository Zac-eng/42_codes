#include "iter.hpp"
#include <iostream>

template <typename T>
static void increment(T& value) {
  value += 1;
}
template <typename T>
static void put_value(T& value) {
  std::cout << value << std::endl;
}
// template void increment<float>(float);


int main(void) {
  int intarr[] = {3, 5, 7, 1, 19, 39};
  float floatarr[] = {1.9f, 4.2f, 3.5f, 91.02f};
  iter(&intarr[0], sizeof(intarr) / sizeof(intarr[0]), put_value);
  iter(&floatarr[0], sizeof(floatarr) / sizeof(floatarr[0]), increment);
  iter(&floatarr[0], sizeof(floatarr) / sizeof(floatarr[0]), put_value);
  return 0;
}
