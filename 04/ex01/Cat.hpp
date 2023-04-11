#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
    private:
        Brain *brain;

    public:
        Cat(void);
        Cat(Cat const &catObj);
        ~Cat(void);
        Cat &operator=(Cat const &rhs);

        Brain *getBrain(void) const;

        virtual void makeSound(void) const;
};

#endif
