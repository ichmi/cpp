#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW1 "\x1b[38;5;220m"
#define YELLOW2 "\x1b[38;5;222m"
#define PURPLE1 "\x1b[38;5;162m"
#define PURPLE2 "\x1b[38;5;90m"
#define PURPLE3 "\x1b[38;5;126m"
#define RED "\x1b[38;5;196m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

class AForm;

class Bureaucrat {
    private:
        std::string const _name;
        int _grade;

    public:
        Bureaucrat(void);
        Bureaucrat(Bureaucrat const &bureaucratObj);
        ~Bureaucrat(void);
        Bureaucrat &operator=(Bureaucrat const &rhs);

        Bureaucrat(std::string const name, int const grade);

        class GradeTooHighException : public std::exception {
            char const *what(void) const throw();
        };
        class GradeTooLowException : public std::exception {
            char const *what(void) const throw();
        };

        std::string const getName(void) const;
        int               getGrade(void) const;

        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(AForm &f);
        void executeForm(AForm &f);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif
