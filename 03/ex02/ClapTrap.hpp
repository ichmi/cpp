#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define ORANGE "\x1b[38;5;208m"
#define ORED "\x1b[38;5;196m"
#define RED "\x1b[38;5;88m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>

class ClapTrap {
    protected:
        std::string _name;
        int         _hitPoints;
        int         _energyPoints;
        int         _attackDamage;

    public:
        ClapTrap(void);
        ClapTrap(ClapTrap const &clapObj);
        ~ClapTrap(void);
        ClapTrap &operator=(ClapTrap const &rhs);

        ClapTrap(std::string name);

        std::string getName(void) const;
        int         getHitPoints(void) const;
        int         getEnergyPoints(void) const;
        int         getAttackDamage(void) const;

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif
