#include "Fixed.hpp"

class Point {

private:
    Fixed   x;
    Fixed   y;

public:
    Point(void);
    Point(float init_x, float init_y);
    Point(const Fixed& init_x, const Fixed& init_y);
    Point(const Point& point);
    Point& operator = (const Point& point);
    bool operator == (const Point &compared) const;
    ~Point();
    const Fixed& getx() const;
    const Fixed& gety() const;
};

Point  operator - (const Point& oper1, const Point& oper2);
