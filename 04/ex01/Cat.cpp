#include "Cat.hpp"

Cat::Cat(void) : Animal(), brain(new Brain()) {
    std::cout << ORANGE "Cat" RES " default constructor called" << std::endl;

    this->type = "Cat";
}

Cat::Cat(Cat const &catObj) : Animal(catObj) {
    std::cout << ORANGE "Cat" RES " copy constructor called" << std::endl;

    this->type = catObj.getType();
    this->brain = new Brain(*catObj.brain);
}

Cat::~Cat(void) {
    std::cout << ORANGE "Cat" RES " destructor called" << std::endl;
    delete this->brain;
}

Cat &Cat::operator=(Cat const &rhs) {
    std::cout << ORANGE "Cat" RES " assignment operator called" << std::endl;

    this->type = rhs.getType();
    this->brain = rhs.brain;

    return *this;
}

void Cat::makeSound(void) const {
    std::cout << ORANGE "Cat" RES " says " GREEN "Meoow!" RES << std::endl;
}

Brain *Cat::getBrain(void) const {
    return this->brain;
}
