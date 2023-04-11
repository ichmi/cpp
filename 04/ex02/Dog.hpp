#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"

class Dog : public AAnimal {
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

