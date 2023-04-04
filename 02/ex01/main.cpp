#include "Fixed.hpp"

int main( void ) {
    std::cout << BLUE "42 subject example" RES << std::endl;
    {
        Fixed a;
        Fixed const b( 10 );
        Fixed const c( 42.42f );
        Fixed const d( b );

        a = Fixed( 1234.4321f );

        std::cout << "a is " << a << std::endl;
        std::cout << "b is " << b << std::endl;
        std::cout << "c is " << c << std::endl;
        std::cout << "d is " << d << std::endl;

        std::cout << "a is " << a.toInt() << " as integer" << std::endl;
        std::cout << "b is " << b.toInt() << " as integer" << std::endl;
        std::cout << "c is " << c.toInt() << " as integer" << std::endl;
        std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    }

    std::cout << BLUE "\nCustom example" RES << std::endl;
    {
        int value;
        Fixed a;

        value = a.getRawBits();
        std::cout << "a.rawBits  : " YELLOW << value << RES << std::endl;
        std::cout << "a.toInt()  : " YELLOW << a.toInt() << RES << std::endl;
        std::cout << "a.toFloat(): " YELLOW << a.toFloat() << RES << std::endl;
        std::cout << "a          : " YELLOW << a << RES << std::endl;

        std::cout << BLUE "\na.setRawBits(1)" RES << std::endl;
        a.setRawBits(1);
        value = a.getRawBits();
        std::cout << "a.rawBits  : " YELLOW << value << RES << std::endl;
        std::cout << "a.toInt()  : " YELLOW << (a.toInt()) << RES << std::endl;
        std::cout << "a.toFloat(): " YELLOW << a.toFloat() << RES << std::endl;
        std::cout << "a          : " YELLOW << a << RES << std::endl;

        std::cout << BLUE "\na.setRawBits(-1)" RES << std::endl;
        a.setRawBits(-1);
        value = a.getRawBits();
        std::cout << "a.rawBits  : " YELLOW << value << RES << std::endl;
        std::cout << "a.toInt()  : " YELLOW << (a.toInt()) << RES << std::endl;
        std::cout << "a.toFloat(): " YELLOW << a.toFloat() << RES << std::endl;
        std::cout << "a          : " YELLOW << a << RES << std::endl;

        std::cout << BLUE "\na.setRawBits(256)" RES << std::endl;
        a.setRawBits(256);
        value = a.getRawBits();
        std::cout << "a.rawBits  : " YELLOW << value << RES << std::endl;
        std::cout << "a.toInt()  : " YELLOW << (a.toInt()) << RES << std::endl;
        std::cout << "a.toFloat(): " YELLOW << a.toFloat() << RES << std::endl;
        std::cout << "a          : " YELLOW << a << RES << std::endl;

        std::cout << BLUE "\na.setRawBits(257)" RES << std::endl;
        a.setRawBits(257);
        value = a.getRawBits();
        std::cout << "a.rawBits  : " YELLOW << value << RES << std::endl;
        std::cout << "a.toInt()  : " YELLOW << (a.toInt()) << RES << std::endl;
        std::cout << "a.toFloat(): " YELLOW << a.toFloat() << RES << std::endl;
        std::cout << "a          : " YELLOW << a << RES << std::endl;

        std::cout << BLUE "\na.setRawBits(512)" RES << std::endl;
        a.setRawBits(512);
        value = a.getRawBits();
        std::cout << "a.rawBits  : " YELLOW << value << RES << std::endl;
        std::cout << "a.toInt()  : " YELLOW << (a.toInt()) << RES << std::endl;
        std::cout << "a.toFloat(): " YELLOW << a.toFloat() << RES << std::endl;
        std::cout << "a          : " YELLOW << a << RES << std::endl;

        std::cout << BLUE "\na.setRawBits(513)" RES << std::endl;
        a.setRawBits(513);
        value = a.getRawBits();
        std::cout << "a.rawBits  : " YELLOW << value << RES << std::endl;
        std::cout << "a.toInt()  : " YELLOW << (a.toInt()) << RES << std::endl;
        std::cout << "a.toFloat(): " YELLOW << a.toFloat() << RES << std::endl;
        std::cout << "a          : " YELLOW << a << RES << std::endl;

        std::cout << BLUE "\na.setRawBits(MAX_INT)" RES << std::endl;
        a.setRawBits(2147483647);
        value = a.getRawBits();
        std::cout << "a.rawBits  : " YELLOW << value << RES << std::endl;
        std::cout << "a.toInt()  : " YELLOW << (a.toInt()) << RES << std::endl;
        std::cout << "a.toFloat(): " YELLOW << a.toFloat() << RES << std::endl;
        std::cout << "a          : " YELLOW << a << RES << std::endl;
    }

    return 0;
}
