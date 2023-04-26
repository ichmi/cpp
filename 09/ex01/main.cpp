#include "RPN.hpp"

int testSubject(void);

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << RED "- " GRAY "Error: invalid number of arguments" RES << std::endl;
        return 1;
    }

    if (std::string(av[1]) == "--eval") {
        return testSubject();
    }

    std::string const expression = av[1];

    try {
        int const result = RPN::eval(expression);
        std::cout << GREEN << result << RES << std::endl;
    } catch (std::exception const &e) {
        std::cerr << RED << e.what() << RES << std::endl;
    }

    return 0;
}

int testSubject(void) {
    std::cout << BLUE "42 subject example: " CYAN "\"8 9 * 9 - 9 - 9 - 4 - 1 +\"" BLUE " = " GREEN "42" RES << std::endl;
    {
        try {
            int const result = RPN::eval("8 9 * 9 - 9 - 9 - 4 - 1 +");
            std::cout << GREEN << result << RES << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\n42 subject example: " CYAN "\"7 7 * 7 -\"" BLUE " = " GREEN "42" RES << std::endl;
    {
        try {
            int const result = RPN::eval("7 7 * 7 -");
            std::cout << GREEN << result << RES << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\n42 subject example: " CYAN "\"1 2 * 2 / 2 * 2 4 - +\"" BLUE " = " GREEN "0" RES << std::endl;
    {
        try {
            int const result = RPN::eval("1 2 * 2 / 2 * 2 4 - +");
            std::cout << GREEN << result << RES << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\n42 subject example: " CYAN "\"(1 + 1)\"" BLUE " = " RED "Error" RES << std::endl;
    {
        try {
            int const result = RPN::eval("(1 + 1)");
            std::cout << GREEN << result << RES << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    return 0;
}
