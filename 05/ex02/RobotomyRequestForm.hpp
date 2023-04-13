#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(RobotomyRequestForm const &obj);
        ~RobotomyRequestForm(void);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

        RobotomyRequestForm(std::string const target);

        virtual void execute(Bureaucrat const &executor) const;
};

typedef RobotomyRequestForm Robotomy;

#endif

