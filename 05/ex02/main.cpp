#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void formSignIn(void) {
    std::cout << BLUE "\nSigning in forms" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 25);
            Shrubbery shruberryForm("foo");
            Robotomy robotomyForm("bar");
            Pardon pardonForm("baz");

            b.signForm(shruberryForm);
            b.signForm(robotomyForm);
            b.signForm(pardonForm);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nSigning in forms" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 26);
            Shrubbery shruberryForm("foo");
            Robotomy robotomyForm("bar");
            Pardon pardonForm("baz");

            b.signForm(shruberryForm);
            b.signForm(robotomyForm);
            b.signForm(pardonForm);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }
}

void formExecution(void) {
    std::cout << BLUE "\nSign in and execute form action" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 137);
            Shrubbery shruberryForm("happy_little");

            b.signForm(shruberryForm);
            shruberryForm.execute(b);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nExecute form action before get signed" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 137);
            Shrubbery shruberryForm("foo");

            shruberryForm.execute(b);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }
}

void invalidExec(void) {
    std::cout << BLUE "\nInvalid ShruberryCreation form execution" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 138);
            Shrubbery shruberryForm("happy_little");

            b.signForm(shruberryForm);
            b.executeForm(shruberryForm);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nInvalid RobotomyRequest form execution" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 46);
            Robotomy robotomyForm("foo");

            b.signForm(robotomyForm);
            b.executeForm(robotomyForm);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nInvalid PresidentialPardon form execution" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 6);
            Pardon pardonForm("foo");

            b.signForm(pardonForm);
            b.executeForm(pardonForm);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }
}

void unsignedInvalidExec(void) {
    std::cout << BLUE "\nInvalid ShruberryCreation form execution/unsigned" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 150);
            Shrubbery shruberryForm("happy_little");

            b.signForm(shruberryForm);
            b.executeForm(shruberryForm);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nInvalid RobotomyRequest form execution/unsigned" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 150);
            Robotomy robotomyForm("foo");

            b.signForm(robotomyForm);
            b.executeForm(robotomyForm);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nInvalid PresidentialPardon form execution/unsigned" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 150);
            Pardon pardonForm("foo");

            b.signForm(pardonForm);
            b.executeForm(pardonForm);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }
}

void validExec(void) {
    std::cout << BLUE "\n\nShruberryCreation form execution" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 137);
            Shrubbery shruberryForm("happy_little");

            b.signForm(shruberryForm);
            b.executeForm(shruberryForm);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nRobotomyRequest form execution" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 45);
            Robotomy robotomyForm("foo");

            b.signForm(robotomyForm);
            b.executeForm(robotomyForm);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nPresidentialPardon form execution" RES << std::endl;
    {
        try {
            Bureaucrat b("Fabio", 5);
            Pardon pardonForm("foo");

            b.signForm(pardonForm);
            b.executeForm(pardonForm);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }
}

int main(void) {
    std::srand(time(NULL));

    std::cout << BLUE "Concrete class object creation" RES << std::endl;
    {
        try {
            Shrubbery shruberryForm("home");
            std::cout << shruberryForm << std::endl;

            Robotomy robotomyForm("foo bar baz");
            std::cout << robotomyForm << std::endl;

            Pardon pardonForm("bRUuh");
            std::cout << pardonForm << std::endl;
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    formSignIn();
    formExecution();

    invalidExec();
    unsignedInvalidExec();
    validExec();
    
    return 0;
}
