#include "Fixed.hpp"

int main( void ) {
    std::cout << BLUE "42 subject example" RES << std::endl;
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }

    std::cout << BLUE "\nComparison operator overloads" RES << std::endl;
    {
        std::cout << "0 == 0: " YELLOW << (Fixed(0) == Fixed(0)) << RES << std::endl;
        std::cout << "0 != 0: " YELLOW << (Fixed(0) != Fixed(0)) << RES << std::endl;
        std::cout << "0 == 1: " YELLOW << (Fixed(0) == Fixed(1)) << RES << std::endl;
        std::cout << "0 != 1: " YELLOW << (Fixed(0) != Fixed(1)) << RES << std::endl;

        std::cout << "5 > 5: " YELLOW << (Fixed(5) > Fixed(5)) << RES << std::endl;
        std::cout << "5 >= 5: " YELLOW << (Fixed(5) >= Fixed(5)) << RES << std::endl;
        std::cout << "5 < 5: " YELLOW << (Fixed(5) < Fixed(5)) << RES << std::endl;
        std::cout << "5 <= 5: " YELLOW << (Fixed(5) <= Fixed(5)) << RES << std::endl;

        std::cout << "-5 > 1: " YELLOW << (Fixed(-5) > Fixed(1)) << RES << std::endl;
        std::cout << "-5 < 1: " YELLOW << (Fixed(-5) < Fixed(1)) << RES << std::endl;
    }

    std::cout << BLUE "\nArithmetic operator overloads" RES << std::endl;
    {
        std::cout << "1 + 1 : " YELLOW << (Fixed(1) + Fixed(1)) << RES << std::endl;
        std::cout << "-5 + 6: " YELLOW << (Fixed(-5) + Fixed(6)) << RES << std::endl;

        std::cout << "1 - 1 : " YELLOW << (Fixed(1) - Fixed(1)) << RES << std::endl;
        std::cout << "0 - 1 : " YELLOW << (Fixed(0) - Fixed(1)) << RES << std::endl;

        std::cout << "2 * 2 : " YELLOW << (Fixed(2) * Fixed(2)) << RES << std::endl;
        std::cout << "-2 * 2: " YELLOW << (Fixed(-2) * Fixed(2)) << RES << std::endl;

        std::cout << "2 / 2 : " YELLOW << (Fixed(2) / Fixed(2)) << RES << std::endl;
        std::cout << "-2 / 2: " YELLOW << (Fixed(-2) / Fixed(2)) << RES << std::endl;
        std::cout << "5 / 2 : " YELLOW << (Fixed(5) / Fixed(2)) << RES << std::endl;

        std::cout << "1.5 + 1.2: " YELLOW << (Fixed(1.5f) + Fixed(1.2f)) << RES << std::endl;
        std::cout << "1.5 - 1.2: " YELLOW << (Fixed(1.5f) - Fixed(1.2f)) << RES << std::endl;
        std::cout << "1.5 * 2  : " YELLOW << (Fixed(1.5f) * Fixed(2)) << RES << std::endl;
        std::cout << "5 / 2.5  : " YELLOW << (Fixed(5) / Fixed(2.5f)) << RES << std::endl;
        std::cout << "1 / 3    : " YELLOW << (Fixed(1) / Fixed(3)) << RES << std::endl;
    }

    std::cout << BLUE "\nIncrement/Decrement operator overloads" RES << std::endl;
    {
        Fixed a;

        std::cout << "a  : " YELLOW << a << RES << std::endl;
        std::cout << "a++: " YELLOW << a++ << RES << std::endl;
        std::cout << "a  : " YELLOW << a << RES << std::endl;
        std::cout << "++a: " YELLOW << ++a << RES << std::endl;
        std::cout << "a  : " YELLOW << a << RES << std::endl;

        std::cout << "a--: " YELLOW << a-- << RES << std::endl;
        std::cout << "a  : " YELLOW << a << RES << std::endl;
        std::cout << "--a: " YELLOW << --a << RES << std::endl;
        std::cout << "a  : " YELLOW << a << RES << std::endl;

        std::cout << "(++a)--: " YELLOW << (++a)-- << RES << std::endl;
        std::cout << "a      : " YELLOW << a << RES << std::endl;
    }

    std::cout << BLUE "\nMin and max methods" RES << std::endl;
    {
        std::cout << "min(0, 0):   " YELLOW << Fixed::min(Fixed(0), Fixed(0)) << RES << std::endl;
        std::cout << "max(0, 0):   " YELLOW << Fixed::max(Fixed(0), Fixed(0)) << RES << std::endl;

        std::cout << "min(10, 11): " YELLOW << Fixed::min(Fixed(10), Fixed(11)) << RES << std::endl;
        std::cout << "max(10, 11): " YELLOW << Fixed::max(Fixed(10), Fixed(11)) << RES << std::endl;

        std::cout << "min(-1, 1):  " YELLOW << Fixed::min(Fixed(-1), Fixed(1)) << RES << std::endl;
        std::cout << "max(-1, 1):  " YELLOW << Fixed::max(Fixed(-1), Fixed(1)) << RES << std::endl;

        std::cout << "min(1.01, 1.02): " YELLOW << Fixed::min(Fixed(1.01f), Fixed(1.02f)) << RES << std::endl;
        std::cout << "max(1.01, 1.02): " YELLOW << Fixed::max(Fixed(1.01f), Fixed(1.02f)) << RES << std::endl;
    }

    std::cout << BLUE "\nMin and max methods with const objects:" RES << std::endl;
    {
        Fixed const a(10);
        Fixed const b(11);

        std::cout << "const min(10, 11): " YELLOW << Fixed::min(a, b) << RES << std::endl;
        std::cout << "const max(10, 11): " YELLOW << Fixed::min(a, b) << RES << std::endl;
    }

    return 0;
}
