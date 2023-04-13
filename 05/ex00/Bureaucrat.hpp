#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define ORANGE "\x1b[38;5;208m"
#define RED "\x1b[38;5;196m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>
#include <string>
#include <exception>

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

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
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);

#endif
