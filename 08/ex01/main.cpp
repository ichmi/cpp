#include "Span.hpp"

int main(void) {
    std::cout << BLUE "42 subject example" RES << std::endl;
    {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    std::cout << BLUE "\nSpan(5) filled" RES << std::endl;
    {
        Span sp(5);

        int const tab[] = {6, 3, 17, 8, 11};
        for (int i = 0; i < 5; ++i) {
            sp.addNumber(tab[i]);
        }

        std::cout << GRAY "size:     " YELLOW << sp.size() << RES << std::endl;
        std::cout << GRAY "capacity: " YELLOW << sp.capacity() << RES << std::endl;
        std::cout << GRAY "Span:     [";
        for (int i = 0; i < 5; ++i) {
            if (i == 4) {
                std::cout << CYAN << tab[i] << RES;
            } else {
                std::cout << CYAN << tab[i] << GRAY ",";
            }
        }
        std::cout << GRAY "]" RES << std::endl;

        std::cout << GRAY "Shortest: " GREEN << sp.shortestSpan() << RES << std::endl;
        std::cout << GRAY "Longest:  " GREEN << sp.longestSpan() << RES << std::endl;
    }

    std::cout << BLUE "\nSpan(1024) filled" RES << std::endl;
    {
        Span sp(1024);

        for (int i = 0; i < 1024; ++i) {
            sp.addNumber(i);
        }
        std::cout << GRAY "capacity: " YELLOW << sp.capacity() << RES << std::endl;
        std::cout << GRAY "Shortest: " GREEN << sp.shortestSpan() << RES << std::endl;
        std::cout << GRAY "Longest:  " GREEN << sp.longestSpan() << RES << std::endl;

        try {
            sp.addNumber(1024);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nSpan(3) one by one" RES << std::endl;
    {
        Span sp(3);
        std::cout << GRAY "size:     " YELLOW << sp.size() << RES << std::endl;
        std::cout << GRAY "capacity: " YELLOW << sp.capacity() << RES << std::endl;

        sp.addNumber(42);
        std::cout << GRAY "\nsize:     " YELLOW << sp.size() << RES << std::endl;
        std::cout << GRAY "capacity: " YELLOW << sp.capacity() << RES << std::endl;

        sp.addNumber(40);
        std::cout << GRAY "\nsize:     " YELLOW << sp.size() << RES << std::endl;
        std::cout << GRAY "capacity: " YELLOW << sp.capacity() << RES << std::endl;

        sp.addNumber(2);
        std::cout << GRAY "\nsize:     " YELLOW << sp.size() << RES << std::endl;
        std::cout << GRAY "capacity: " YELLOW << sp.capacity() << RES << std::endl;

        std::cout << GRAY "\nShortest: " GREEN << sp.shortestSpan() << RES << std::endl;
        std::cout << GRAY "Longest:  " GREEN << sp.longestSpan() << RES << std::endl;
    }

    std::cout << BLUE "\nSpan(3) filling 1 (raise exception)" RES << std::endl;
    {
        try {
            Span sp(3);
            sp.addNumber(42);
            std::cout << GRAY "size:     " YELLOW << sp.size() << RES << std::endl;
            std::cout << GRAY "Shortest: " GREEN << sp.shortestSpan() << RES << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Span sp(3);
            sp.addNumber(42);
            std::cout << GRAY "\nsize:     " YELLOW << sp.size() << RES << std::endl;
            std::cout << GRAY "Longest:  " GREEN << sp.longestSpan() << RES << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nSpan(3) exceed capacity (raise exception)" RES << std::endl;
    {
        try {
            Span sp(3);
            std::cout << GRAY "capacity: " YELLOW << sp.capacity() << RES << std::endl;
            std::cout << GRAY "size:     " YELLOW << sp.size() << RES << std::endl;
            sp.addNumber(1);
            std::cout << GRAY "size:     " YELLOW << sp.size() << RES << std::endl;
            sp.addNumber(2);
            std::cout << GRAY "size:     " YELLOW << sp.size() << RES << std::endl;
            sp.addNumber(10);
            std::cout << GRAY "size:     " YELLOW << sp.size() << RES << std::endl;
            sp.addNumber(-42);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nSpan(10) filled by iterators" RES << std::endl;
    {
        int const fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
        int const fibSize = sizeof(fib) / sizeof(fib[0]);

        std::vector<int> vec;
        for (int i = 0; i < fibSize; ++i) {
            vec.push_back(fib[i]);
        }

        Span sp(fibSize);
        sp.addNumber(vec.begin(), vec.end());

        std::cout << GRAY "size:     " YELLOW << sp.size() << RES << std::endl;
        std::cout << GRAY "capacity: " YELLOW << sp.capacity() << RES << std::endl;
        std::cout << GRAY "Span:     [";
        for (int i = 0; i < fibSize; ++i) {
            if (i == fibSize - 1) {
                std::cout << CYAN << fib[i] << RES;
            } else {
                std::cout << CYAN << fib[i] << GRAY ",";
            }
        }
        std::cout << GRAY "]" RES << std::endl;

        std::cout << GRAY "Shortest: " GREEN << sp.shortestSpan() << RES << std::endl;
        std::cout << GRAY "Longest:  " GREEN << sp.longestSpan() << RES << std::endl;
    }

    std::cout << BLUE "\nIterator range will exceed Span size (raise exception)" RES << std::endl;
    {
        int const fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
        int const fibSize = sizeof(fib) / sizeof(fib[0]);

        std::vector<int> vec;
        for (int i = 0; i < fibSize; ++i) {
            vec.push_back(fib[i]);
        }

        try {
            Span sp(fibSize - 1);
            std::cout << GRAY "Span capacity: " CYAN << sp.capacity() << RES << std::endl;
            std::cout << GRAY "vector size:   " YELLOW << vec.size() << RES << std::endl;
            sp.addNumber(vec.begin(), vec.end());
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    return 0;
}
