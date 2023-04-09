#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    public:
        FragTrap(void);
        FragTrap(FragTrap const &fragObj);
        ~FragTrap(void);
        FragTrap &operator=(FragTrap const &rhs);

        FragTrap(std::string name);

        void highFivesGuys(void);
};

#endif
