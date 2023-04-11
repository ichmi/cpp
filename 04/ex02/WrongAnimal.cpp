#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Unknown wrong animal") {
    std::cout << YELLOW "WrongAnimal" RES " default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &wrongAnimalObj) {
    std::cout << YELLOW "WrongAnimal" RES " copy constructor called" << std::endl;

    *this = wrongAnimalObj;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << YELLOW "WrongAnimal" RES " destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
    std::cout << YELLOW "WrongAnimal" RES " assignment operator called" << std::endl;

    this->type = rhs.getType();

    return *this;
}

std::string WrongAnimal::getType(void) const {
    return this->type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << YELLOW "WrongAnimal" RES " does some " GREEN "weird" RES " sound" << std::endl;
}
