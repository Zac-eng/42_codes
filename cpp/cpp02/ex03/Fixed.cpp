#include "Fixed.hpp"

Fixed::Fixed(void) {
    this->_value = 0;
}

Fixed::Fixed(const Fixed &object) {
    this->_value = object.getRawBits();
}

Fixed::Fixed(const int value) {
    _value = value * (1 << _fractional);
}

Fixed::Fixed(const float value) {
    _value = static_cast<int>(value * (1 << _fractional) + FUDGE_FACTOR);
}

Fixed::~Fixed(void) {}

Fixed& Fixed::operator = (const Fixed &object) {
    this->_value = object.getRawBits();
    return *this;
}

bool    Fixed::operator > (const Fixed& compared) const {
    return _value > compared.getRawBits();
}

bool    Fixed::operator < (const Fixed& compared) const {
    return _value < compared.getRawBits();
}

bool    Fixed::operator >= (const Fixed& compared) const {
    return _value >= compared.getRawBits();
}

bool    Fixed::operator <= (const Fixed& compared) const {
    return _value <= compared.getRawBits();
}

bool    Fixed::operator == (const Fixed& compared) const {
    return _value == compared.getRawBits();
}

bool    Fixed::operator != (const Fixed& compared) const {
    return _value != compared.getRawBits();
}

Fixed   operator + (const Fixed& oper1, const Fixed& oper2) {
    return Fixed(oper1.toFloat() + oper2.toFloat());
};

Fixed   operator - (const Fixed& oper1, const Fixed& oper2) {
    return Fixed(oper1.toFloat() - oper2.toFloat());
};

Fixed   operator * (const Fixed& oper1, const Fixed& oper2) {
    return Fixed(oper1.toFloat() * oper2.toFloat());
};

Fixed   operator / (const Fixed& oper1, const Fixed& oper2) {
    return Fixed(oper1.toFloat() / oper2.toFloat());
};

Fixed&  Fixed::operator ++ (void) {
    this->_value += 1;
    return *this;
}

Fixed   Fixed::operator ++ (int) {
    this->_value += 1;
    return *this;
}

Fixed&  Fixed::operator -- () {
    this->_value += 1;
    return *this;
}

Fixed   Fixed::operator -- (int) {
    this->_value += 1;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& object) {
    out << object.toFloat();
    return out;
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw << _fractional;
}

float Fixed::toFloat(void) const {
    float float_value = static_cast<float>(_value) / (1 << _fractional);
    return float_value;
}

int Fixed::toInt(void) const {
    return _value / (1 << _fractional);
}
