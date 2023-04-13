#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(PresidentialPardonForm const &obj);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

        PresidentialPardonForm(std::string const target);

        virtual void execute(Bureaucrat const &executor) const;
};

typedef PresidentialPardonForm Pardon;

#endif


