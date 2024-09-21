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
    this->_value = value * (1 << this->_fractional);
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    this->_value = static_cast<int>(value * (1 << this->_fractional)) + FUDGE_FACTOR;
}

Fixed& Fixed::operator = (const Fixed &object) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = object.getRawBits();
    return *this;
}

bool    Fixed::operator > (const Fixed& compared) const {
    return this->_value > compared.getRawBits() + FUDGE_FACTOR;
}

bool    Fixed::operator < (const Fixed& compared) const {
    return this->_value - FUDGE_FACTOR < compared.getRawBits();
}

bool    Fixed::operator >= (const Fixed& compared) const {
    return *this > compared || *this == compared;
}

bool    Fixed::operator <= (const Fixed& compared) const {
    return *this < compared || *this == compared;
}

bool    Fixed::operator == (const Fixed& compared) const {
    int diff;

    if (*this > compared)
        diff = this->_value - compared.getRawBits();
    else
        diff = compared.getRawBits() - this->_value;
    return diff <= FUDGE_FACTOR;
}

bool    Fixed::operator != (const Fixed& compared) const {
    return !(*this == compared);
}

Fixed   operator + (const Fixed& oper1, const Fixed& oper2) {
    Fixed   result;
    result.setRawBits(oper1.getRawBits() + oper2.getRawBits());
    return result;
};

Fixed   operator - (const Fixed& oper1, const Fixed& oper2) {
    Fixed   result;
    result.setRawBits(oper1.getRawBits() - oper2.getRawBits());
    return result;
};

Fixed   operator * (const Fixed& oper1, const Fixed& oper2) {
    Fixed   result;
    result.setRawBits(oper1.getRawBits() * oper2.getRawBits() / (1 << oper1.getFractional()));
    return result;
};

Fixed   operator / (const Fixed& oper1, const Fixed& oper2) {
    Fixed   result;
    result.setRawBits(oper1.getRawBits() * (1 << oper1.getFractional()) / oper2.getRawBits());
    return result;
};

Fixed&  Fixed::operator ++ (void) {
    this->_value++;
    return *this;
}

Fixed   Fixed::operator ++ (int) {
    Fixed   result(*this);
    this->_value++;
    return result;
}

Fixed&  Fixed::operator -- () {
    this->_value--;
    return *this;
}

Fixed   Fixed::operator -- (int) {
    Fixed   result(*this);
    this->_value--;
    return result;
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

int Fixed::getFractional(void) const {
    return this->_fractional;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_value) / (1 << this->_fractional);
}

int Fixed::toInt(void) const {
    return this->_value / (1 << this->_fractional);
}
