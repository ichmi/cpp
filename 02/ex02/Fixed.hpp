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

        bool   operator==(Fixed const &rhs) const;
        bool   operator!=(Fixed const &rhs) const;
        bool   operator>=(Fixed const &rhs) const;
        bool   operator<=(Fixed const &rhs) const;
        bool   operator>(Fixed const &rhs) const;
        bool   operator<(Fixed const &rhs) const;

        Fixed  operator+(Fixed const &rhs);
        Fixed  operator-(Fixed const &rhs);
        Fixed  operator*(Fixed const &rhs);
        Fixed  operator/(Fixed const &rhs);

        Fixed &operator++(void);
        Fixed  operator++(int);
        Fixed &operator--(void);
        Fixed  operator--(int);


        int   getRawBits(void) const;
        void  setRawBits(int const raw);
        float toFloat(void) const;
        int   toInt(void) const;

        static Fixed       &min(Fixed &lhs, Fixed &rhs);
        static const Fixed &min(Fixed const &lhs, Fixed const &rhs);
        static Fixed       &max(Fixed &lhs, Fixed &rhs);
        static const Fixed &max(Fixed const &lhs, Fixed const &rhs);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixedPointNumber);

#endif
