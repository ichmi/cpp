#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define ORANGE "\x1b[38;5;208m"
#define ORED "\x1b[38;5;196m"
#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>
#include "Brain.hpp"

class AAnimal {
    protected:
        std::string type;

    public:
        AAnimal(void);
        AAnimal(AAnimal const &animalObj);
        virtual ~AAnimal(void);
        AAnimal &operator=(AAnimal const &rhs);

        std::string getType(void) const;

        virtual void makeSound(void) const = 0;
};

#endif
