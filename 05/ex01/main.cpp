#include "Form.hpp"

int main(void) {
    std::cout << BLUE "Form default constructor" RES << std::endl;
    {
        try {
            Form f;
            std::cout << f << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nForm parametric creation" RES << std::endl;
    {
        try {
            Form f("foo", 1, 1);
            std::cout << f << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Form f("foo", 10, 10);
            std::cout << f << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Form f("foo", 150, 150);
            std::cout << f << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nForm parametric creation (invalid)" RES << std::endl;
    {
        try {
            Form f("foo", 0, 1);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Form f("foo", 1, 0);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Form f("foo", 151, 150);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }

        try {
            Form f("foo", 150, 151);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nSign in success" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 42);
            Form f("Basic math", 120, 120);
            std::cout << f << std::endl;
            b.signForm(f);
            std::cout << f << std::endl;
            b.signForm(f);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nSign in fail" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 42);
            Form f("Advanced math", 20, 20);
            std::cout << f << std::endl;
            b.signForm(f);
            std::cout << f << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nSigning multiple forms" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 8);
            Form UFRGS("UFRGS", 120, 120);
            Form ITA("ITA", 20, 20);
            Form MIT("MIT", 1, 1);

            std::cout << b << std::endl;
            std::cout << UFRGS << std::endl;
            std::cout << ITA << std::endl;
            std::cout << MIT << std::endl;

            b.signForm(UFRGS);
            b.signForm(ITA);
            std::cout << UFRGS << std::endl;
            std::cout << ITA << std::endl;

            b.signForm(MIT);
            std::cout << MIT << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    return 0;
}
