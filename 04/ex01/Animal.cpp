#include "Animal.hpp"

Animal::Animal(void) : type("Unknown") {
    std::cout << YELLOW "Animal" RES << " default constructor called" << std::endl;
}

Animal::Animal(Animal const &animalObj) {
    std::cout << YELLOW "Animal" RES << " copy constructor called" << std::endl;

    *this = animalObj;
}

Animal::~Animal(void) {
    std::cout << YELLOW "Animal" RES << " destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs) {
    std::cout << YELLOW "Animal" RES << " assignment operator called" << std::endl;

    this->type = rhs.getType();

    return *this;
}

std::string Animal::getType(void) const {
    return this->type;
}

void Animal::makeSound(void) const {
    std::cout << YELLOW "Animal" RES << " does some " << GREEN "menacing growling" RES << " noise..." << std::endl;
}
