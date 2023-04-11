#include "Dog.hpp"

Dog::Dog(void) : AAnimal(), brain(new Brain()) {
    std::cout << ORED "Dog" RES " default constructor called" << std::endl;

    this->type = "Dog";
}

Dog::Dog(Dog const &dogObj) : AAnimal(dogObj) {
    std::cout << ORED "Dog" RES " copy constructor called" << std::endl;

    this->type = dogObj.getType();
    this->brain = new Brain(*dogObj.brain);
}

Dog::~Dog(void) {
    std::cout << ORED "Dog" RES " destructor called" << std::endl;
    delete this->brain;
}

Dog &Dog::operator=(Dog const &rhs) {
    std::cout << ORED "Dog" RES " assignment operator called" << std::endl;

    this->type = rhs.getType();
    this->brain = rhs.brain;

    return *this;
}

void Dog::makeSound(void) const {
    std::cout << ORED "Dog" RES " says " GREEN "Au au!" RES << std::endl;
}

Brain *Dog::getBrain(void) const {
    return this->brain;
}
