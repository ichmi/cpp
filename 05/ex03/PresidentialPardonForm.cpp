#include "PresidentialPardonForm.hpp"

Pardon::PresidentialPardonForm(void) : AForm() {
    std::cout << PURPLE1 "PresidentialPardonForm" RES " default constructor called" << std::endl;

    this->setTarget("default");
}

Pardon::PresidentialPardonForm(Pardon const &obj) : AForm(obj) {
    std::cout << PURPLE1 "PresidentialPardonForm" RES " copy constructor called" << std::endl;

    this->setTarget(obj.getTarget());
    this->setName(obj.getName());
    this->setIsSigned(obj.getIsSigned());
    this->setSignInGradeRequired(obj.getSignInGradeRequired());
    this->setExecuteGradeRequired(obj.getExecuteGradeRequired());
}

Pardon::~PresidentialPardonForm(void) {
    std::cout << PURPLE1 "PresidentialPardonForm" RES " destructor called" << std::endl;
}

Pardon &Pardon::operator=(Pardon const &rhs) {
    std::cout << PURPLE1 "PresidentialPardonForm" RES " assignment operator called" << std::endl;

    this->setTarget(rhs.getTarget());
    this->setName(rhs.getName());
    this->setIsSigned(rhs.getIsSigned());
    this->setSignInGradeRequired(rhs.getSignInGradeRequired());
    this->setExecuteGradeRequired(rhs.getExecuteGradeRequired());

    return *this;
}

Pardon::PresidentialPardonForm(std::string const target) :
    AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << PURPLE1 "PresidentialPardonForm" RES " named constructor called" << std::endl;

    if (target.empty()) {
        this->setTarget("default");
    } else {
        this->setTarget(target);
    }
}

void Pardon::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);

    std::cout << BLUE << this->target << RES " has been pardoned by " GRAY "Zaphod Beeblebrox" RES << std::endl;
}
