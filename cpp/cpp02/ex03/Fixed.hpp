#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

# ifndef FUDGE_FACTOR
#  define FUDGE_FACTOR 1
# endif

class Fixed {
private:
    int _value;
    static const int _fractional = 8;
public:
    Fixed(void);
    Fixed(const Fixed &object);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed(void);
    Fixed&  operator = (const Fixed &object);
    bool    operator > (const Fixed& compared) const;
    bool    operator < (const Fixed& compared) const;
    bool    operator >= (const Fixed& compared) const;
    bool    operator <= (const Fixed& compared) const;
    bool    operator == (const Fixed& compared) const;
    bool    operator != (const Fixed& compared) const;
    Fixed&  operator ++ ();
    Fixed   operator ++ (int);
    Fixed&  operator -- ();
    Fixed   operator -- (int);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
    static Fixed&  min(Fixed& obj1, Fixed& obj2) {
        if (obj1 > obj2)
            return obj2;
        else
            return obj1;
    }
    static const Fixed&  min(const Fixed& obj1, const Fixed& obj2) {
        if (obj1 > obj2)
            return obj2;
        else
            return obj1;
    }
    static Fixed&  max(Fixed& obj1, Fixed& obj2) {
        if (obj1 < obj2)
            return obj2;
        else
            return obj1;
    }
    static const Fixed&  max(const Fixed& obj1, const Fixed& obj2) {
        if (obj1 < obj2)
            return obj2;
        else
            return obj1;
    }
};

std::ostream&   operator << (std::ostream& out, const Fixed& object);
Fixed           operator + (const Fixed& oper1, const Fixed& oper2);
Fixed           operator - (const Fixed& oper1, const Fixed& oper2);
Fixed           operator * (const Fixed& oper1, const Fixed& oper2);
Fixed           operator / (const Fixed& oper1, const Fixed& oper2);

#endif
