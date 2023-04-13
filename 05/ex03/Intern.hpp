#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

enum { SHRUBBERY = 1, ROBOTOMY, PARDON };

class Intern {
    private:
        AForm *_newShrubberyCreationForm(std::string const formName) const;
        AForm *_newRobotomyRequestForm(std::string const formName) const;
        AForm *_newPresidentialPardonForm(std::string const formName) const;

    public:
        Intern(void);
        Intern(Intern const &internObj);
        ~Intern(void);
        Intern &operator=(Intern const &rhs);

        class FormNotFoundException : public std::exception {
            char const *what(void) const throw();
        };

        AForm *makeForm(std::string formName, std::string formTarget) const;
};

#endif
