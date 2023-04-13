#include "Intern.hpp"

Intern::Intern(void) {
    std::cout << CYAN "Intern" RES " default constructor called" << std::endl;
}

Intern::Intern(Intern const &internObj) {
    std::cout << CYAN "Intern" RES " copy constructor called" << std::endl;

    *this = internObj;
}

Intern::~Intern(void) {
    std::cout << CYAN "Intern" RES " destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &rhs) {
    std::cout << CYAN "Intern" RES " assignment operator called" << std::endl;

    (void)rhs;

    return *this;
}

char const *Intern::FormNotFoundException::what(void) const throw() {
    return "Invalid form name";
}

AForm *Intern::_newShrubberyCreationForm(std::string const formTarget) const {
    return new ShrubberyCreationForm(formTarget);
}

AForm *Intern::_newRobotomyRequestForm(std::string const formTarget) const {
    return new RobotomyRequestForm(formTarget);
}

AForm *Intern::_newPresidentialPardonForm(std::string const formTarget) const {
    return new PresidentialPardonForm(formTarget);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget) const {
    int const numberOfOptions = 3;
    std::string const formOptions[numberOfOptions] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int option = 0;
    for (int i = 0; i < numberOfOptions; ++i) {
        if (formName == formOptions[i]) {
            option = i + 1;
        }
    }
    
    switch (option) {
        case SHRUBBERY:
            return _newShrubberyCreationForm(formTarget);
        case ROBOTOMY:
            return _newRobotomyRequestForm(formTarget);
        case PARDON:
            return _newPresidentialPardonForm(formTarget);
        default:
            throw FormNotFoundException();
    }
}
