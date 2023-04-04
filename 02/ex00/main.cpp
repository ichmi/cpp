#include "Fixed.hpp"

int main( void ) {
    std::cout << BLUE "42 subject example" RES << std::endl;
    {
        Fixed a;
        Fixed b( a );
        Fixed c;

        c = b;

        std::cout << a.getRawBits() << std::endl;
        std::cout << b.getRawBits() << std::endl;
        std::cout << c.getRawBits() << std::endl;
    }

    std::cout << BLUE "\nCustom example" RES << std::endl;
    {
        int value;

        Fixed a;
        a.setRawBits(11);

        value = a.getRawBits();
        std::cout << "a: " YELLOW << value << RES << std::endl;

        Fixed b(a);
        value = b.getRawBits();
        std::cout << "b: " YELLOW << value << RES << std::endl;

        b.setRawBits(22);

        value = a.getRawBits();
        std::cout << "a: " YELLOW << value << RES << std::endl;

        value = b.getRawBits();
        std::cout << "b: " YELLOW << value << RES << std::endl;

        a.setRawBits(33);

        value = a.getRawBits();
        std::cout << "a: " YELLOW << value << RES << std::endl;

        value = b.getRawBits();
        std::cout << "b: " YELLOW << value << RES << std::endl;
    }

    return 0;
}
