#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("N/A"), _grade(LOWEST_GRADE) {
    std::cout << YELLOW2 "Bureaucrat" RES " default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade) {
    std::cout << YELLOW2 "Bureaucrat" RES " copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << YELLOW2 "Bureaucrat" RES " destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
    std::cout << YELLOW2 "Bureaucrat" RES " assignment operator called" << std::endl;

    const_cast<std::string &>(this->_name) = rhs._name;
    this->_grade = rhs._grade;

    return *this;
}

Bureaucrat::Bureaucrat(std::string const name, int const grade) : _name(name), _grade(grade) {
    std::cout << YELLOW2 "Bureaucrat" RES " named constructor" << std::endl;

    if (this->_grade > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    if (this->_grade < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b) {
    return os << BLUE << b.getName() << RES ", bureaucrat grade " GREEN << b.getGrade() << RES;
}

std::string const Bureaucrat::getName(void) const {
    return this->_name;
}

void Bureaucrat::incrementGrade(void) {
    if (this->_grade <= HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    this->_grade -= 1;
}

void Bureaucrat::decrementGrade(void) {
    if (this->_grade >= LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    this->_grade += 1;
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

char const *Bureaucrat::GradeTooHighException::what(void) const throw() {
    return "Bureaucrat grade is too high";
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw() {
    return "Bureaucrat grade is too low";
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << BLUE << this->_name << RES " signed " BLUE << form.getName() << RES << std::endl;
    } catch (std::exception const &e) {
        std::cerr << BLUE << this->_name << RES " couldn’t sign " BLUE << form.getName() << RES " because " RED << e.what() << RES << std::endl;
    }
}

void Bureaucrat::executeForm(AForm &form) {
    try {
        form.execute(*this);
        std::cout << BLUE << this->_name << RES " executed " BLUE << form.getName() << RES << std::endl;
    } catch (std::exception const &e) {
        std::cerr << BLUE << this->_name << RES " couldn’t execute " BLUE << form.getName() << RES " because " RED << e.what() << RES << std::endl;
    }
}
