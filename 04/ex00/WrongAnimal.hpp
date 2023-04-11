#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define ORANGE "\x1b[38;5;208m"
#define ORED "\x1b[38;5;196m"
#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>

class WrongAnimal {
    protected:
        std::string type;

    public:
        WrongAnimal(void);
        WrongAnimal(WrongAnimal const &wrongAnimalObj);
        virtual ~WrongAnimal(void);
        WrongAnimal &operator=(WrongAnimal const &rhs);

        std::string getType(void) const;

        void makeSound(void) const;
};

#endif
