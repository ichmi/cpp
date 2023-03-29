#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL) {
    if (name.empty()) {
        this->_name = "Default Human B";
    } else {
        this->_name = name;
    }
}

void HumanB::attack(void) const {
    if (!this->_weapon) {
        std::cout << this->_name << " attacks with their Hands" << std::endl;
        return ;
    }

    std::string const weapon = (*this->_weapon).getType();
    std::cout << this->_name << " attacks with their " << weapon << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
}
