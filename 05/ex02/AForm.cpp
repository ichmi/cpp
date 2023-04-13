#include "AForm.hpp"

AForm::AForm(void) : 
    _name("generic"),
    _isSigned(false),
    _signInGradeRequired(LOWEST_GRADE),
    _executeGradeRequired(LOWEST_GRADE)
{
    std::cout << YELLOW1 "Form" RES " default constructor called" << std::endl;
}

AForm::AForm(AForm const &src) :
    _name(src._name),
    _isSigned(src._isSigned),
    _signInGradeRequired(src._signInGradeRequired),
    _executeGradeRequired(src._executeGradeRequired)
{
    std::cout << YELLOW1 "Form" RES " copy constructor called" << std::endl;
}

AForm::~AForm(void) {
    std::cout << YELLOW1 "Form" RES " destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &rhs) {
    std::cout << YELLOW1 "Form" RES " assignment operator called" << std::endl;

    const_cast<std::string &>(this->_name) = rhs._name;
    this->_isSigned = rhs._isSigned;
    const_cast<int &>(this->_signInGradeRequired) = rhs._signInGradeRequired;
    const_cast<int &>(this->_executeGradeRequired) = rhs._executeGradeRequired;

    return *this;
}

AForm::AForm(std::string const name, int const signInGrade, int const execGrade) :
    _name(name),
    _isSigned(false),
    _signInGradeRequired(signInGrade),
    _executeGradeRequired(execGrade)
{
    std::cout << YELLOW1 "Form" RES " name constructor called" << std::endl;

    if (this->_signInGradeRequired > LOWEST_GRADE ||
        this->_executeGradeRequired > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    if (this->_signInGradeRequired < HIGHEST_GRADE ||
        this->_executeGradeRequired < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
}

std::ostream &operator<<(std::ostream &os, AForm const &f) {
    bool const isSigned = f.getIsSigned();
    std::string const color = isSigned ? GREEN : RED;

    return os
    << "Form(" GRAY "name=" BLUE
    << f.getName()                 << GRAY ",signInGrade=" GREEN
    << f.getSignInGradeRequired()  << GRAY ",execGrade=" GREEN
    << f.getExecuteGradeRequired() << GRAY ",isSigned=" << color
    << isSigned << RES ")";
}

std::string AForm::getName(void) const {
    return this->_name;
}

bool AForm::getIsSigned(void) const {
    return this->_isSigned;
}

int AForm::getSignInGradeRequired(void) const {
    return this->_signInGradeRequired;
}

int AForm::getExecuteGradeRequired(void) const {
    return this->_executeGradeRequired;
}

std::string AForm::getTarget(void) const {
    return this->target;
}

void AForm::setName(std::string const name) {
    const_cast<std::string &>(this->_name) = name;
}

void AForm::setIsSigned(bool const state) {
    const_cast<bool &>(this->_isSigned) = state;
}

void AForm::setSignInGradeRequired(int const grade) {
    const_cast<int &>(this->_signInGradeRequired) = grade;
}

void AForm::setExecuteGradeRequired(int const grade) {
    const_cast<int &>(this->_executeGradeRequired) = grade;
}

void AForm::setTarget(std::string target) {
    if (target.empty()) {
        throw InvalidTargetException();
    }

    this->target = target;
}

char const *AForm::GradeTooHighException::what(void) const throw() {
    return "Grade value is too high to the form";
}

char const *AForm::GradeTooLowException::what(void) const throw() {
    return "Grade is too low to sign in this form";
}

char const *AForm::FormSignedException::what(void) const throw() {
    return "Form is already signed";
}

char const *AForm::FormNotSignedException::what(void) const throw() {
    return "Form is not signed yet";
}

char const *AForm::InvalidTargetException::what(void) const throw() {
    return "Invalid target";
}

char const *AForm::LowGradeExecutionException::what(void) const throw() {
    return "Bureaucrat grade is to low to execute form action";
}

void AForm::beSigned(Bureaucrat const &b) {
    if (b.getGrade() > this->_signInGradeRequired) {
        throw GradeTooLowException();
    }
    if (this->_isSigned) {
        throw FormSignedException();
    }

    this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (this->_isSigned == false) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->_executeGradeRequired) {
        throw LowGradeExecutionException();
    }
}
