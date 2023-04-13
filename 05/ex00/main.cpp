#include "Bureaucrat.hpp"

int main(void) {
    std::cout << BLUE "Valid range grade" RES << std::endl;
    {
        try {
            Bureaucrat b("foo", 150);
            std::cout << b << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Bureaucrat b("bar", 1);
            std::cout << b << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nInvalid range grade constructor" RES << std::endl;
    {
        try {
            Bureaucrat b("foo", 151);
            std::cout << b << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Bureaucrat b("bar", 0);
            std::cout << b << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nBureaucrat properties" RES << std::endl;
    {
        try {
            Bureaucrat b("foo", 42);
            std::cout << "Bureaucrat(" BLUE << b.getName() << RES ", " GREEN << b.getGrade() << RES << ")" << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Bureaucrat b("bar", 1);
            std::cout << "Bureaucrat(" BLUE << b.getName() << RES ", " GREEN << b.getGrade() << RES << ")" << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nIncrement grade" RES << std::endl;
    {
        try {
            Bureaucrat b("foo", 10);
            std::cout << b << std::endl;
            for (int i = 0; i < 5; ++i) {
                b.incrementGrade();
            }
            std::cout << b << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Bureaucrat b("bar", 6);
            std::cout << b << std::endl;
            for (int i = 0; i < 5; ++i) {
                b.incrementGrade();
            }
            std::cout << b << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Bureaucrat b("baz", 5);
            std::cout << b << std::endl;
            for (int i = 0; i < 5; ++i) {
                b.incrementGrade();
            }
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nDecrement grade" RES << std::endl;
    {
        try {
            Bureaucrat b("foo", 5);
            std::cout << b << std::endl;
            for (int i = 0; i < 5; ++i) {
                b.decrementGrade();
            }
            std::cout << b << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Bureaucrat b("bar", 145);
            std::cout << b << std::endl;
            for (int i = 0; i < 5; ++i) {
                b.decrementGrade();
            }
            std::cout << b << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Bureaucrat b("baz", 146);
            std::cout << b << std::endl;
            for (int i = 0; i < 5; ++i) {
                b.decrementGrade();
            }
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    return 0;
}
