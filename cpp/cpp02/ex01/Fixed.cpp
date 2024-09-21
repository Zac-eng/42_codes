#include "Fixed.hpp"

Fixed::Fixed(void) {
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

Fixed::Fixed(const Fixed &object) {
    std::cout << "Copy constructor called" << std::endl;
    *this = object;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << this->_fractional;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = static_cast<int>(value * (1 << this->_fractional) + FUDGE_FACTOR);
}

Fixed& Fixed::operator = (const Fixed &object) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = object.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& object) {
    out << object.toFloat();
    return out;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->getRawBits()) / (1 << this->_fractional);
}

int Fixed::toInt(void) const {
    return this->getRawBits() / (1 << this->_fractional);
}
