#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "---The test Added by hmiyazak---"  << std::endl;
    std::cout << Fixed(0) << std::endl;
    std::cout << Fixed(0.0f) << std::endl;
    Fixed lhs(10);
    Fixed rhs(3.3f);
    std::cout << lhs - rhs << std::endl;
    std::cout << "lhs:" << lhs << std::endl;
    std::cout << "rhs:" << rhs << std::endl;
    std::cout << (Fixed(0) == Fixed(0.0f) ? "true" : "false") << std::endl;
    std::cout << (Fixed(0) == Fixed(0) ? "true" : "false") << std::endl;
    std::cout << (a < b ? "true" : "false") << std::endl;

    std::cout << Fixed(100) / Fixed(2.5f) << std::endl;
    std::cout << Fixed(10.0f) / Fixed(4) << std::endl;
    std::cout << (Fixed(100) == Fixed(100.0f) ? "true" : "false") << std::endl;
    std::cout << (Fixed(100) != Fixed(100.0f) ? "true" : "false") << std::endl;
    std::cout << Fixed( 42.42f ) << std::endl;

    return 0;
}
