#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    Point a(0.0f, 0.0f);
    Point b(0.0f, 5.0f);
    Point c(5.0f, 0.0f);
    Point p(2.4f, 2.5f);
    std::cout << (bsp(a, b, c, p) ? "true" : "false") << std::endl;
    return 0;
}
