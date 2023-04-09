#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
    std::cout << ORED "FragTrap" RES << " default constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &fragObj) : ClapTrap(fragObj) {
    std::cout << ORED "FragTrap" RES << " copy constructor called" << std::endl;

    *this = fragObj;
}

FragTrap::~FragTrap(void) {
    std::cout << ORED "FragTrap" RES << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
    std::cout << ORED "FragTrap" RES << " assignment operator called" << std::endl;

    this->_name = rhs.getName();
    this->_hitPoints = rhs.getHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_attackDamage = rhs.getAttackDamage();

    return *this;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << ORED "FragTrap" RES << " named constructor called" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

void FragTrap::highFivesGuys(void) {
    std::cout << ORED "FragTrap " BLUE << this->_name << RES " requests a High five! o/" << std::endl;
}
