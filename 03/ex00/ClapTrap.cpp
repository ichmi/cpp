#include "ClapTrap.hpp"
#include <cstdlib>

ClapTrap::ClapTrap(void) :
    _name("Default Clap"),
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0) {
    std::cout << YELLOW "ClapTrap" RES << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : 
    _hitPoints(10),
    _energyPoints(10),
    _attackDamage(0) {
    std::cout << YELLOW "ClapTrap" RES << " named constructor called" << std::endl;

    if (name.empty()) {
        this->_name = "Generic Clap";
    } else {
        this->_name = name;
    }
}

ClapTrap::ClapTrap(ClapTrap const &clapObj) {
    std::cout << YELLOW "ClapTrap" RES << " copy constructor called" << std::endl;

    *this = clapObj;
}

ClapTrap::~ClapTrap(void) {
    std::cout << YELLOW "ClapTrap" RES << " destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
    std::cout << YELLOW "ClapTrap" RES << " assignment operator called" << std::endl;

    this->_name = rhs.getName();
    this->_hitPoints = rhs.getHitPoints();
    this->_energyPoints = rhs.getEnergyPoints();
    this->_attackDamage = rhs.getAttackDamage();

    return *this;
}

std::string ClapTrap::getName(void) const {
    return this->_name;
}

int ClapTrap::getHitPoints(void) const {
    return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const {
    return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void) const {
    return this->_attackDamage;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_hitPoints <= 0) {
        std::cout << YELLOW "ClapTrap " BLUE << this->_name << RES " is already dead." << std::endl;
        return ;
    }
    if (this->_energyPoints <= 0) {
        std::cout << YELLOW "ClapTrap " BLUE << this->_name << RES " doesnt have enough energy points to attack." << std::endl;
        return ;
    }
    if (target.empty()) {
        std::cout << YELLOW "ClapTrap " BLUE << this->_name << RES " is training hard" << std::endl;
    } else {
        std::cout << YELLOW "ClapTrap " BLUE << this->_name << RES " attacks " RED << target << RES ", causing " YELLOW << this->_attackDamage << RES " points of damage!" << std::endl;
    }

    this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_energyPoints <= 0) {
        return ;
    }
    if (this->_hitPoints <= 0) {
        std::cout << YELLOW "ClapTrap " BLUE << this->_name << RES " is already dead." << std::endl;
        return ;
    }

    std::cout << YELLOW "ClapTrap " BLUE << this->_name << RES " took " RED << amount << RES " damage!"<< std::endl;
    if (amount > static_cast<unsigned int>(this->_hitPoints)) {
        this->_hitPoints = 0;
    } else {
        this->_hitPoints -= amount;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << YELLOW "ClapTrap " BLUE << this->_name << RES " is already dead." << std::endl;
        return ;
    }
    if (this->_energyPoints <= 0) {
        std::cout << YELLOW "ClapTrap " BLUE << this->_name << RES " doesnt have enough energy points to be repaired." << std::endl;
        return ;
    }
    std::cout << YELLOW "ClapTrap " BLUE << this->_name << RES " repaired " GREEN << amount << RES " hit points!"<< std::endl;

    this->_hitPoints += amount;
    this->_energyPoints--;
}
