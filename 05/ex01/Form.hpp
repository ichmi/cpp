#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form {
    private:
        std::string const _name;
        bool              _isSigned;
        int const         _signInGradeRequired;
        int const         _executeGradeRequired;

    public:
        Form(void);
        Form(Form const &formObj);
        ~Form(void);
        Form &operator=(Form const &rhs);

        Form(std::string const name, int const signInGrade, int const execGrade);

        class GradeTooHighException : public std::exception {
            char const *what(void) const throw();
        };
        class GradeTooLowException : public std::exception {
            char const *what(void) const throw();
        };
        class FormSignedException : public std::exception {
            char const *what(void) const throw();
        };

        std::string getName(void) const;
        bool        getIsSigned(void) const;
        int         getSignInGradeRequired(void) const;
        int         getExecuteGradeRequired(void) const;

        void beSigned(Bureaucrat const &b);
};

std::ostream &operator<<(std::ostream &os, Form const &f);

#endif
