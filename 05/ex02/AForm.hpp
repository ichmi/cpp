#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm {
    private:
        std::string const _name;
        bool              _isSigned;
        int const         _signInGradeRequired;
        int const         _executeGradeRequired;
    
    protected:
        std::string target;

        std::string getTarget(void) const;
        void        setTarget(std::string const target);

    public:
        AForm(void);
        AForm(AForm const &formObj);
        ~AForm(void);
        AForm &operator=(AForm const &rhs);

        AForm(std::string const name, int const signInGrade, int const execGrade);

        class GradeTooHighException : public std::exception {
            char const *what(void) const throw();
        };
        class GradeTooLowException : public std::exception {
            char const *what(void) const throw();
        };
        class FormSignedException : public std::exception {
            char const *what(void) const throw();
        };
        class FormNotSignedException : public std::exception {
            char const *what(void) const throw();
        };
        class InvalidTargetException : public std::exception {
            char const *what(void) const throw();
        };
        class LowGradeExecutionException : public std::exception {
            char const *what(void) const throw();
        };

        std::string  getName(void) const;
        bool         getIsSigned(void) const;
        int          getSignInGradeRequired(void) const;
        int          getExecuteGradeRequired(void) const;
        void         setName(std::string const name);
        void         setIsSigned(bool const state);
        void         setSignInGradeRequired(int const grade);
        void         setExecuteGradeRequired(int const grade);

        void         beSigned(Bureaucrat const &b);
        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm const &f);

#endif
