#include "ScavTrap.hpp"

int main(void) {
    std::cout << BLUE "Default constructor" RES << std::endl;
    {
        ScavTrap scav;
    }

    std::cout << BLUE "\nClap, Scav default constructors" RES << std::endl;
    {
        ClapTrap clap;
        ScavTrap scav;
    }

    std::cout << BLUE "\nDefault named constructor" RES << std::endl;
    {
        ScavTrap scav("");
        std::cout << "Scav name: " GREEN << scav.getName() << RES << std::endl;
    }

    std::cout << BLUE "\nNamed constructor" RES << std::endl;
    {
        ScavTrap scav("Foo");
        std::cout << "Scav name: " GREEN << scav.getName() << RES << std::endl;
    }

    std::cout << BLUE "\nCopy constructor" RES << std::endl;
    {
        ScavTrap scav("Foo");
        ScavTrap copyScav(scav);
        std::cout << "Scav original name: " GREEN << scav.getName() << RES << std::endl;
        std::cout << "Scav copy name:     " GREEN << copyScav.getName() << RES << std::endl;
    }

    std::cout << BLUE "\nAssignment operator" RES << std::endl;
    {
        ScavTrap scav;
        std::cout << "Scav name before: " GREEN << scav.getName() << RES << std::endl;
        scav = ScavTrap("Foo");
        std::cout << "Scav name after:  " GREEN << scav.getName() << RES << std::endl;
    }

    std::cout << BLUE "\nScavTrap instance properties" RES << std::endl;
    {
        ScavTrap scav("scav");
        std::cout << ORANGE "ScavTrap " << BLUE << scav.getName() << RES " has " GREEN << scav.getHitPoints() << RES " hp" << std::endl;
        std::cout << ORANGE "ScavTrap " << BLUE << scav.getName() << RES " has " GREEN << scav.getEnergyPoints() << RES " ep" << std::endl;
        std::cout << ORANGE "ScavTrap " << BLUE << scav.getName() << RES " has " GREEN << scav.getAttackDamage() << RES " ad" << std::endl;

        ClapTrap clap("clap");
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getHitPoints() << RES " hp" << std::endl;
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getEnergyPoints() << RES " ep" << std::endl;
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getAttackDamage() << RES " ad" << std::endl;
    }

    std::cout << BLUE "\nAttack" RES << std::endl;
    {
        ScavTrap scav("Foo");
        scav.attack("");

        ScavTrap targetScav("Dummy");
        scav.attack(targetScav.getName());
    }

    std::cout << BLUE "\nClap methods used by Scav object" RES << std::endl;
    {
        ScavTrap scav("scav");
        std::cout << ORANGE "ScavTrap " << BLUE << scav.getName() << RES " has " GREEN << scav.getHitPoints() << RES " hp" << std::endl;
        std::cout << ORANGE "ScavTrap " << BLUE << scav.getName() << RES " has " GREEN << scav.getEnergyPoints() << RES " ep" << std::endl;

        scav.takeDamage(50);
        std::cout << ORANGE "ScavTrap " << BLUE << scav.getName() << RES " has " GREEN << scav.getHitPoints() << RES " hp" << std::endl;

        scav.beRepaired(50);
        std::cout << ORANGE "ScavTrap " << BLUE << scav.getName() << RES " has " GREEN << scav.getHitPoints() << RES " hp" << std::endl;

        std::cout << ORANGE "ScavTrap " << BLUE << scav.getName() << RES " has " GREEN << scav.getEnergyPoints() << RES " ep" << std::endl;
    }

    std::cout << BLUE "\nGuardgate" RES << std::endl;
    {
        ScavTrap scav("Foo");
        scav.guardGate();

        ScavTrap dummyScav("");
        dummyScav.guardGate();
    }

    return 0;
}
