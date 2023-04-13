#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
    std::srand(time(NULL));

    std::cout << BLUE "42 Subject example" RES << std::endl;
    {
        Intern someRandomIntern;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        delete rrf;
    }

    std::cout << BLUE "\nIntern form creation" RES << std::endl;
    {
        Intern someRandomIntern;

        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "foo");
        std::cout << *scf << std::endl;
        delete scf;

        AForm* rrf = someRandomIntern.makeForm("robotomy request", "bar");
        std::cout << *rrf << std::endl;
        delete rrf;

        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "baz");
        std::cout << *ppf << std::endl;
        delete ppf;
    }

    std::cout << BLUE "\nInvalid form name" RES << std::endl;
    {
        Intern someRandomIntern;

        try {
            AForm* f = someRandomIntern.makeForm("request", "wait, what?");
            std::cout << *f << std::endl;
            delete f;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nSigned form and execution" RES << std::endl;
    {
        Intern someRandomIntern;

        try {
            Bureaucrat b("Fabio", 5);
            AForm* rrf = someRandomIntern.makeForm("robotomy request", "qwerty");
            std::cout << *rrf << std::endl;
            b.signForm(*rrf);
            std::cout << *rrf << std::endl;
            b.executeForm(*rrf);
            delete rrf;

            AForm* ppf = someRandomIntern.makeForm("presidential pardon", "foo");
            std::cout << *ppf << std::endl;
            b.signForm(*ppf);
            std::cout << *ppf << std::endl;
            b.executeForm(*ppf);
            delete ppf;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }
    
    return 0;
}
