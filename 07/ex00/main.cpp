#include "whatever.hpp"

int main( void ) {
    std::cout << BLUE "42 subject example (int, std::string)" RES << std::endl;
    {
        int a = 2;
        int b = 3;

        std::cout << GRAY "Before: A=" GREEN << a << GRAY ", B=" YELLOW << b << RES << std::endl;
        ::swap( a, b );
        std::cout << GRAY "After:  A=" YELLOW << a << GRAY ", B=" GREEN << b << RES << std::endl;
        std::cout << GRAY "::min = " RES << ::min( a, b ) << std::endl;
        std::cout << GRAY "::max = " RES << ::max( a, b ) << std::endl;

        std::string c = "chaine1";
        std::string d = "chaine2";

        std::cout << GRAY "\nBefore: C=" GREEN << c << GRAY ", D=" YELLOW << d << RES << std::endl;
        ::swap(c, d);
        std::cout << GRAY "After:  C=" YELLOW << c << GRAY ", D=" GREEN << d << RES << std::endl;
        std::cout << GRAY "::min = " RES << ::min( c, d ) << std::endl;
        std::cout << GRAY "::max = " RES << ::max( c, d ) << std::endl;
    }

    std::cout << BLUE "\nFloating type arguments" RES << std::endl;
    {
        float a = 2.01f;
        float b = 3.84f;

        std::cout << GRAY "Before: A=" GREEN << a << GRAY ", B=" YELLOW << b << RES << std::endl;
        ::swap( a, b );
        std::cout << GRAY "After:  A=" YELLOW << a << GRAY ", B=" GREEN << b << RES << std::endl;
        std::cout << GRAY "::min = " RES << ::min( a, b ) << std::endl;
        std::cout << GRAY "::max = " RES << ::max( a, b ) << std::endl;
    }

    std::cout << BLUE "\nDouble type arguments" RES << std::endl;
    {
        double a = .123;
        double b = .321;

        std::cout << GRAY "Before:  A=" GREEN << a << GRAY ", B=" YELLOW << b << RES << std::endl;
        ::swap(a, b);
        std::cout << GRAY "After:   A=" YELLOW << a << GRAY ", B=" GREEN << b << RES << std::endl;
        std::cout << GRAY "::min = " RES << ::min( a, b ) << std::endl;
        std::cout << GRAY "::max = " RES << ::max( a, b ) << std::endl;
    }

    std::cout << BLUE "\nlong double type arguments" RES << std::endl;
    {
        long double a = 123.123;
        long double b = 123.124;

        std::cout << GRAY "Before:  A=" GREEN << a << GRAY ", B=" YELLOW << b << RES << std::endl;
        ::swap(a, b);
        std::cout << GRAY "After:   A=" YELLOW << a << GRAY ", B=" GREEN << b << RES << std::endl;
        std::cout << GRAY "::min = " RES << ::min( a, b ) << std::endl;
        std::cout << GRAY "::max = " RES << ::max( a, b ) << std::endl;
    }

    return 0;
}
