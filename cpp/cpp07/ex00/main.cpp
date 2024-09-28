#include "whatever.hpp"
#include <iostream>

int main(void) {
  {
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
  }
  int a = 2;
  int b = 3;
  ::swap( a, b );
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
  std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
  std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
  return 0;
}
