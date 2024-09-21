#include "Point.hpp"

Point::Point(void): x(0), y(0) {}

Point::Point(float init_x, float init_y): x(init_x), y(init_y) {}

Point::Point(const Fixed& init_x, const Fixed& init_y): x(init_x), y(init_y) {}

Point::Point(const Point& point): x(point.getx()), y(point.gety()) {}

Point::~Point() {}

Point& Point::operator = (const Point& point) {
    this->x = point.getx();
    this->y = point.gety();
    return *this;
}

bool Point::operator == (const Point &compared) const {
    return (this->getx() == compared.getx() && this->gety() == compared.gety());
}

Point  operator - (const Point& oper1, const Point& oper2) {
    return Point(oper1.getx() - oper2.getx(), oper1.gety() - oper2.gety());
}

const Fixed& Point::getx() const {
    return this->x;
}

const Fixed& Point::gety() const {
    return this->y;
}
