#include "iter.hpp"

void printString(std::string &v) {
    std::cout << GRAY "string: " YELLOW << v << RES << std::endl;
}

void printInt(int &v) {
    std::cout << GRAY "int: " YELLOW << v << RES << std::endl;
}

void printFloat(float &v) {
    std::cout << GRAY "float: " YELLOW << v << RES << std::endl;
}

void printConstFloat(float const &v) {
    std::cout << GRAY "const float: " YELLOW << v << RES << std::endl;
}

void printDouble(double &v) {
    std::cout << GRAY "double: " YELLOW << v << RES << std::endl;
}

void printLongDouble(long double &v) {
    std::cout << GRAY "long double: " YELLOW << v << RES << std::endl;
}

void printConstLongDouble(long double const &v) {
    std::cout << GRAY "const long double: " YELLOW << v << RES << std::endl;
}

int main(void) {
    std::cout << BLUE "int iteration" RES << std::endl;
    {
        int    seq[] = {1, 2, 3, 4, 5};
        size_t len = sizeof(seq) / sizeof(seq[0]);
        ::iter(seq, len, print);
    }

    std::cout << BLUE "\nstring iteration" RES << std::endl;
    {
        std::string names[] = {"foo", "bar", "baz"};
        size_t len = sizeof(names) / sizeof(names[0]);
        ::iter(names, len, print);
    }

    std::cout << BLUE "\nFloat iteration" RES << std::endl;
    {
        float    real[] = {3.141f, 2.718f, 1.618f, 186.282f};
        size_t len = sizeof(real) / sizeof(real[0]);
        ::iter(real, len, print);
    }

    std::cout << BLUE "\nDouble iteration" RES << std::endl;
    {
        float    real[] = {3.141f, 2.718f, 1.618f, 186.282f};
        size_t len = sizeof(real) / sizeof(real[0]);
        ::iter(real, len, print);
    }

    std::cout << BLUE "\nconst int iteration" RES << std::endl;
    {
        int const seq[] = {1, 2};
        size_t len = sizeof(seq) / sizeof(seq[0]);
        ::iter(seq, len, print);
    }

    std::cout << BLUE "\nint iteration with custom function" RES << std::endl;
    {
        int seq[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        size_t len = sizeof(seq) / sizeof(seq[0]);
        ::iter(seq, len, printInt);
    }

    std::cout << BLUE "\nlong double iteration with custom function" RES << std::endl;
    {
        long double real[] = {3.141, 2.718};
        size_t len = sizeof(real) / sizeof(real[0]);
        ::iter(real, len, printLongDouble);
    }

    std::cout << BLUE "\nconst long double iteration with custom function" RES << std::endl;
    {
        long double const real[] = {3.141, 2.718f, 1.618, 186.282, .01, 42.001, 123.1};
        size_t len = sizeof(real) / sizeof(real[0]);
        ::iter(real, len, printConstLongDouble);
    }

    return 0;
}
