#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
    private:
        Brain *brain;

    public:
        Dog(void);
        Dog(Dog const &dogObj);
        ~Dog(void);
        Dog &operator=(Dog const &rhs);

        Brain *getBrain(void) const;

        virtual void makeSound(void) const;
};

#endif

