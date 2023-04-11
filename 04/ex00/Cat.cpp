#include "Cat.hpp"

Cat::Cat(void) : Animal() {
    std::cout << ORANGE "Cat" RES " default constructor called" << std::endl;

    this->type = "Cat";
}

Cat::Cat(Cat const &catObj) : Animal(catObj) {
    std::cout << ORANGE "Cat" RES " copy constructor called" << std::endl;

    this->type = catObj.getType();
    *this = catObj;
}

Cat::~Cat(void) {
    std::cout << ORANGE "Cat" RES " destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
    std::cout << ORANGE "Cat" RES " assignment operator called" << std::endl;

    this->type = rhs.getType();

    return *this;
}

void Cat::makeSound(void) const {
    std::cout << ORANGE "Cat" RES " says " GREEN "Meoow!" RES << std::endl;
}
