#include "FragTrap.hpp"

int main(void) {
    std::cout << BLUE "Default constructor" RES << std::endl;
    {
        FragTrap frag;
    }

    std::cout << BLUE "\nClap, Trap default constructors" RES << std::endl;
    {
        ClapTrap clap;
        FragTrap frag;
    }

    std::cout << BLUE "\nDefault named constructor" RES << std::endl;
    {
        FragTrap frag("");
        std::cout << "frag name: " GREEN << frag.getName() << RES << std::endl;
    }

    std::cout << BLUE "\nNamed constructor" RES << std::endl;
    {
        FragTrap frag("Foo");
        std::cout << "frag name: " GREEN << frag.getName() << RES << std::endl;
    }

    std::cout << BLUE "\nCopy constructor" RES << std::endl;
    {
        FragTrap frag("Foo");
        FragTrap copyfrag(frag);
        std::cout << "frag original name: " GREEN << frag.getName() << RES << std::endl;
        std::cout << "frag copy name:     " GREEN << copyfrag.getName() << RES << std::endl;
    }

    std::cout << BLUE "\nAssignment operator" RES << std::endl;
    {
        FragTrap frag;
        std::cout << "frag name before: " GREEN << frag.getName() << RES << std::endl;
        frag = FragTrap("Foo");
        std::cout << "frag name after:  " GREEN << frag.getName() << RES << std::endl;
    }

    std::cout << BLUE "\nFragTrap instance properties" RES << std::endl;
    {
        FragTrap frag("frag");
        std::cout << ORED "FragTrap " << BLUE << frag.getName() << RES " has " GREEN << frag.getHitPoints() << RES " hp" << std::endl;
        std::cout << ORED "FragTrap " << BLUE << frag.getName() << RES " has " GREEN << frag.getEnergyPoints() << RES " ep" << std::endl;
        std::cout << ORED "FragTrap " << BLUE << frag.getName() << RES " has " GREEN << frag.getAttackDamage() << RES " ad" << std::endl;

        ClapTrap clap("clap");
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getHitPoints() << RES " hp" << std::endl;
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getEnergyPoints() << RES " ep" << std::endl;
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getAttackDamage() << RES " ad" << std::endl;
    }

    std::cout << BLUE "\nAttack" RES << std::endl;
    {
        FragTrap frag("Foo");
        frag.attack("");

        FragTrap targetfrag("Dummy");
        frag.attack(targetfrag.getName());
    }

    std::cout << BLUE "\nClap methods used by Frag object" RES << std::endl;
    {
        FragTrap frag("frag");
        std::cout << ORED "FragTrap " << BLUE << frag.getName() << RES " has " GREEN << frag.getHitPoints() << RES " hp" << std::endl;
        std::cout << ORED "FragTrap " << BLUE << frag.getName() << RES " has " GREEN << frag.getEnergyPoints() << RES " ep" << std::endl;

        frag.takeDamage(50);
        std::cout << ORED "FragTrap " << BLUE << frag.getName() << RES " has " GREEN << frag.getHitPoints() << RES " hp" << std::endl;

        frag.beRepaired(50);
        std::cout << ORED "FragTrap " << BLUE << frag.getName() << RES " has " GREEN << frag.getHitPoints() << RES " hp" << std::endl;

        std::cout << ORED "FragTrap " << BLUE << frag.getName() << RES " has " GREEN << frag.getEnergyPoints() << RES " ep" << std::endl;
    }

    std::cout << BLUE "\nHiFivesGuys" RES << std::endl;
    {
        FragTrap frag("Foo");
        frag.highFivesGuys();
    }

    return 0;
}
