#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
    std::cout << ORANGE "ScavTrap" RES << " default constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &scavObj) : ClapTrap(scavObj) {
    std::cout << ORANGE "ScavTrap" RES << " copy constructor called" << std::endl;

    *this = scavObj;
}

ScavTrap::~ScavTrap(void) {
    std::cout << ORANGE "ScavTrap" RES << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
    std::cout << ORANGE "ScavTrap" RES << " assignment operator called" << std::endl;

    this->_name = rhs.getName();
    this->_hitPoints = rhs.getHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_attackDamage = rhs.getAttackDamage();

    return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << ORANGE "ScavTrap" RES << " named constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

void ScavTrap::attack(const std::string& target) {
    if (this->_hitPoints <= 0) {
        std::cout << ORANGE "ScavTrap " BLUE << this->_name << RES " is already dead." << std::endl;
        return ;
    }
    if (this->_energyPoints <= 0) {
        std::cout << ORANGE "ScavTrap " BLUE << this->_name << RES " doesnt have enough energy points to attack." << std::endl;
        return ;
    }
    if (target.empty()) {
        std::cout << ORANGE "ScavTrap " BLUE << this->_name << RES " is training hard" << std::endl;
    } else {
        std::cout << ORANGE "ScavTrap " BLUE << this->_name << RES " attacks " RED << target << RES ", causing " YELLOW << this->_attackDamage << RES " points of damage!" << std::endl;
    }

    this->_energyPoints--;
}

void ScavTrap::guardGate(void) {
    std::cout << ORANGE "ScavTrap " BLUE << this->_name << RES " is now in Gatekepper mode" << std::endl;
}
