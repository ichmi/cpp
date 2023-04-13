#include "RobotomyRequestForm.hpp"

Robotomy::RobotomyRequestForm(void) : AForm() {
    std::cout << PURPLE2 "RobotomyRequestForm" RES " default constructor called" << std::endl;

    this->setTarget("default");
}

Robotomy::RobotomyRequestForm(Robotomy const &obj) : AForm(obj) {
    std::cout << PURPLE2 "RobotomyRequestForm" RES " copy constructor called" << std::endl;

    this->setTarget(obj.getTarget());
    this->setName(obj.getName());
    this->setIsSigned(obj.getIsSigned());
    this->setSignInGradeRequired(obj.getSignInGradeRequired());
    this->setExecuteGradeRequired(obj.getExecuteGradeRequired());
}

Robotomy::~RobotomyRequestForm(void) {
    std::cout << PURPLE2 "RobotomyRequestForm" RES " destructor called" << std::endl;
}

Robotomy &Robotomy::operator=(Robotomy const &rhs) {
    std::cout << PURPLE2 "RobotomyRequestForm" RES " assignment operator called" << std::endl;

    this->setTarget(rhs.getTarget());
    this->setName(rhs.getName());
    this->setIsSigned(rhs.getIsSigned());
    this->setSignInGradeRequired(rhs.getSignInGradeRequired());
    this->setExecuteGradeRequired(rhs.getExecuteGradeRequired());

    return *this;
}

Robotomy::RobotomyRequestForm(std::string const target) :
    AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << PURPLE2 "RobotomyRequestForm" RES " named constructor called" << std::endl;

    if (target.empty()) {
        this->setTarget("default");
    } else {
        this->setTarget(target);
    }
}

void Robotomy::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);

    std::cout << GRAY "~ DRILLING NOISES ~" RES << std::endl;

    if (std::rand() % 2) {
        std::cout << BLUE << this->target << RES " has been " GREEN "successfully robotomized" RES << std::endl;
    } else {
        std::cout << BLUE << this->target << "'s" << RED " Robotomy has failed" RES << std::endl;
    }
}
