#include "whatever.hpp"
#include <iostream>

int main(void) {
  std::string jp = "¥";
  std::string us = "$";
  int smaller = 11;
  int larger = 13;
  float eq_left = 10.5f;
  float eq_right = 10.5f;

  std::cout << "before swap: jp: " << jp << ": us: " << us << std::endl;
  swap(jp, us);
  std::cout << "after swap: jp: " << jp << ": us: " << us << std::endl;
  std::cout << min(smaller, larger) << std::endl;
  std::cout << max(eq_left, eq_right) << std::endl;
  std::cout << "pointer check: " << &eq_right << " : " << &max(eq_left, eq_right) << std::endl;
  return 0;
}
