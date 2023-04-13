#include "ShrubberyCreationForm.hpp"

Shrubbery::ShrubberyCreationForm(void) : AForm() {
    std::cout << PURPLE3 "ShrubberyCreationForm" RES " default constructor called" << std::endl;

    this->setTarget("default");
}

Shrubbery::ShrubberyCreationForm(Shrubbery const &obj) : AForm(obj) {
    std::cout << PURPLE3 "ShrubberyCreationForm" RES " copy constructor called" << std::endl;

    this->setTarget(obj.getTarget());
    this->setName(obj.getName());
    this->setIsSigned(obj.getIsSigned());
    this->setSignInGradeRequired(obj.getSignInGradeRequired());
    this->setExecuteGradeRequired(obj.getExecuteGradeRequired());
}

Shrubbery::~ShrubberyCreationForm(void) {
    std::cout << PURPLE3 "ShrubberyCreationForm" RES " destructor called" << std::endl;
}

Shrubbery &Shrubbery::operator=(Shrubbery const &rhs) {
    std::cout << PURPLE3 "ShrubberyCreationForm" RES " assignment operator called" << std::endl;

    this->setTarget(rhs.getTarget());
    this->setName(rhs.getName());
    this->setIsSigned(rhs.getIsSigned());
    this->setSignInGradeRequired(rhs.getSignInGradeRequired());
    this->setExecuteGradeRequired(rhs.getExecuteGradeRequired());

    return *this;
}

Shrubbery::ShrubberyCreationForm(std::string const target) :
    AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << PURPLE3 "ShrubberyCreationForm" RES " named constructor called" << std::endl;

    if (target.empty()) {
        this->setTarget("default");
    } else {
        this->setTarget(target);
    }
}

char const *Shrubbery::FileManagementException::what(void) const throw() {
    return "Error managing output file descriptor";
}

void Shrubbery::execute(Bureaucrat const &executor) const {
    AForm::execute(executor);

    std::string const outfile = this->target + "_shrubbery";
    std::ofstream ofs(outfile.c_str(), std::fstream::out | std::fstream::trunc);
    if (ofs.fail() || ofs.bad()) {
        throw FileManagementException();
    }
    ofs << ASCII_TREE;
    ofs.close();
}
