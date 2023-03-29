#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name) : name(name) {}

Zombie::~Zombie(void) {
    std::cout << this->name << " was killed..." << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string const name) {
    this->name = name;
}
