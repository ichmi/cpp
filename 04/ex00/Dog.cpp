#include "Dog.hpp"

Dog::Dog(void) : Animal() {
    std::cout << ORED "Dog" RES " default constructor called" << std::endl;

    this->type = "Dog";
}

Dog::Dog(Dog const &dogObj) : Animal(dogObj) {
    std::cout << ORED "Dog" RES " copy constructor called" << std::endl;

    this->type = dogObj.getType();
    *this = dogObj;
}

Dog::~Dog(void) {
    std::cout << ORED "Dog" RES " destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs) {
    std::cout << ORED "Dog" RES " assignment operator called" << std::endl;

    this->type = rhs.getType();

    return *this;
}

void Dog::makeSound(void) const {
    std::cout << ORED "Dog" RES " says " GREEN "Au au!" RES << std::endl;
}
