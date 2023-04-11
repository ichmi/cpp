#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("Unknown") {
    std::cout << YELLOW "AAnimal" RES << " default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &animalObj) {
    std::cout << YELLOW "AAnimal" RES << " copy constructor called" << std::endl;

    *this = animalObj;
}

AAnimal::~AAnimal(void) {
    std::cout << YELLOW "AAnimal" RES << " destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs) {
    std::cout << YELLOW "AAnimal" RES << " assignment operator called" << std::endl;

    this->type = rhs.getType();

    return *this;
}

std::string AAnimal::getType(void) const {
    return this->type;
}
