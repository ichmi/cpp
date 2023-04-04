#ifndef FIXED_HPP
#define FIXED_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define RES "\x1b[0m"

#include <iostream>
#include <istream>
#include <cmath>

class Fixed {
    private:
        static int const _fractionalBitsNumber;
        int _rawBits;

    public:
        Fixed(void);
        Fixed(Fixed const &fixedRef);
        Fixed(int const integerValue);
        Fixed(float const floatValue);
        ~Fixed(void);

        Fixed &operator=(Fixed const &rhs);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixedPointNumber);

#endif
