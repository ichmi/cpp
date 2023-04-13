#include "Form.hpp"

Form::Form(void) : 
    _name("generic"),
    _isSigned(false),
    _signInGradeRequired(LOWEST_GRADE),
    _executeGradeRequired(LOWEST_GRADE)
{
    std::cout << YELLOW "Form" RES " default constructor called" << std::endl;
}

Form::Form(Form const &src) :
    _name(src._name),
    _isSigned(src._isSigned),
    _signInGradeRequired(src._signInGradeRequired),
    _executeGradeRequired(src._executeGradeRequired)
{
    std::cout << YELLOW "Form" RES " copy constructor called" << std::endl;
}

Form::~Form(void) {
    std::cout << YELLOW "Form" RES " destructor called" << std::endl;
}

Form &Form::operator=(Form const &rhs) {
    std::cout << YELLOW "Form" RES " assignment operator called" << std::endl;

    const_cast<std::string &>(this->_name) = rhs._name;
    this->_isSigned = rhs._isSigned;
    const_cast<int &>(this->_signInGradeRequired) = rhs._signInGradeRequired;
    const_cast<int &>(this->_executeGradeRequired) = rhs._executeGradeRequired;

    return *this;
}

Form::Form(std::string const name, int const signInGrade, int const execGrade) :
    _name(name),
    _isSigned(false),
    _signInGradeRequired(signInGrade),
    _executeGradeRequired(execGrade)
{
    std::cout << YELLOW "Form" RES " name constructor called" << std::endl;

    if (this->_signInGradeRequired > LOWEST_GRADE ||
        this->_executeGradeRequired > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    if (this->_signInGradeRequired < HIGHEST_GRADE ||
        this->_executeGradeRequired < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
}

std::ostream &operator<<(std::ostream &os, Form const &f) {
    bool const isSigned = f.getIsSigned();
    std::string const color = isSigned ? GREEN : RED;

    return os
    << "Form(" GRAY "name=" BLUE
    << f.getName()                 << GRAY ",signInGrade=" GREEN
    << f.getSignInGradeRequired()  << GRAY ",execGrade=" GREEN
    << f.getExecuteGradeRequired() << GRAY ",isSigned=" << color
    << isSigned << RES ")";
}

std::string Form::getName(void) const {
    return this->_name;
}

bool Form::getIsSigned(void) const {
    return this->_isSigned;
}

int Form::getSignInGradeRequired(void) const {
    return this->_signInGradeRequired;
}

int Form::getExecuteGradeRequired(void) const {
    return this->_executeGradeRequired;
}

char const *Form::GradeTooHighException::what(void) const throw() {
    return "Grade value is too high to the form";
}

char const *Form::GradeTooLowException::what(void) const throw() {
    return "Grade is too low to sign in this form";
}

char const *Form::FormSignedException::what(void) const throw() {
    return "Form is already signed";
}

void Form::beSigned(Bureaucrat const &b) {
    if (b.getGrade() > this->_signInGradeRequired) {
        throw GradeTooLowException();
    }
    if (this->_isSigned) {
        throw FormSignedException();
    }

    this->_isSigned = true;
}
