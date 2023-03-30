#include "Zombie.hpp"

Zombie::Zombie(void) {}

Zombie::Zombie(std::string name) {
	if (name.empty()) {
		this->name = "Generic Zombie";
		return ;
	}
	this->name = name;
}

Zombie::~Zombie(void) {
    std::cout << this->name << " was killed..." << std::endl;
}

Zombie* newZombie(std::string name) {
	if (name.empty()) {
		return new Zombie("");
	}
    return new Zombie(name);
}

void randomChump(std::string name) {
    Zombie zombieInstance = Zombie(name);
	zombieInstance.announce();
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
