#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
    if (type.empty()) {
        this->type = "Hands";
    } else {
        this->type = type;
    }
}

const std::string &Weapon::getType(void) const {
    return this->type;
}

void Weapon::setType(std::string value) {
    if (value.empty()) {
		this->type = "Generic weapon";
    } else {
	    this->type = value;
	}
}
