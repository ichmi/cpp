#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
    std::cout << ORANGE "WrongCat" RES << " default constructor called" << std::endl;

    this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &catObj) : WrongAnimal(catObj) {
    std::cout << ORANGE "WrongCat" RES << " copy constructor called" << std::endl;

    this->type = catObj.getType();
    *this = catObj;
}

WrongCat::~WrongCat(void) {
    std::cout << ORANGE "WrongCat" RES << " destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
    std::cout << ORANGE "WrongCat" RES << " assignment operator called" << std::endl;

    this->type = rhs.getType();

    return *this;
}

void WrongCat::makeSound(void) const {
    std::cout << ORANGE "WrongCat" RES " says " GREEN "meow meow" RES << std::endl;
}
