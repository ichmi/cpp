#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    public:
        ScavTrap(void);
        ScavTrap(ScavTrap const &scavObj);
        ~ScavTrap(void);
        ScavTrap &operator=(ScavTrap const &rhs);

        ScavTrap(std::string name);

        void attack(const std::string& target);
        void guardGate(void);
};

#endif
