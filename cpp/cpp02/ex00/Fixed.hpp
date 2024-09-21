#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed {
private:
    int _value;
    static const int _fractional = 8;
public:
    Fixed(void);
    Fixed(const Fixed &object);
    Fixed &operator = (const Fixed &object);
    ~Fixed(void);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
