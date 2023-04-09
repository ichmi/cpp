#include "ClapTrap.hpp"

int main(void) {
    std::cout << BLUE "Default constructor" RES << std::endl;
    {
        ClapTrap clap;
    }

    std::cout << BLUE "\nNamed constructor" RES << std::endl;
    {
        ClapTrap clap("Foo");
        std::cout << "Clap name: " GREEN << clap.getName() << RES << std::endl;
    }

    std::cout << BLUE "\nCopy constructor" RES << std::endl;
    {
        ClapTrap clap("Foo");
        ClapTrap copyClap(clap);
        std::cout << "Clap original name: " GREEN << clap.getName() << RES << std::endl;
        std::cout << "Clap copy name:     " GREEN << copyClap.getName() << RES << std::endl;
    }

    std::cout << BLUE "\nAssignment operator" RES << std::endl;
    {
        ClapTrap clap;
        std::cout << "Clap name before: " GREEN << clap.getName() << RES << std::endl;
        clap = ClapTrap("Foo");
        std::cout << "Clap name after:  " GREEN << clap.getName() << RES << std::endl;
    }

    std::cout << BLUE "\nAttack" RES << std::endl;
    {
        ClapTrap clap("Foo");
        clap.attack("");

        ClapTrap targetClap("Dummy");
        clap.attack(targetClap.getName());
    }

    std::cout << BLUE "\nHit points" RES << std::endl;
    {
        ClapTrap clap("Foo");
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getHitPoints() << RES " hp" << std::endl;

        clap.takeDamage(1);
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getHitPoints() << RES " hp" << std::endl;

        clap.takeDamage(9);
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getHitPoints() << RES " hp" << std::endl;

        clap.takeDamage(1);
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getHitPoints() << RES " hp" << std::endl;


        ClapTrap dummyClap("Dummy");
        std::cout << YELLOW "ClapTrap " << BLUE << dummyClap.getName() << RES " has " GREEN << dummyClap.getHitPoints() << RES " hp" << std::endl;

        dummyClap.takeDamage(1024);
        std::cout << YELLOW "ClapTrap " << BLUE << dummyClap.getName() << RES " has " GREEN << dummyClap.getHitPoints() << RES " hp" << std::endl;

        dummyClap.takeDamage(1);
    }

    std::cout << BLUE "\nEnergy points and beRepaired method" RES << std::endl;
    {
        ClapTrap clap("Foo");
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getEnergyPoints() << RES " energy points" << std::endl;

        clap.attack("");
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getEnergyPoints() << RES " energy points" << std::endl;

        clap.attack("Dummy");
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getEnergyPoints() << RES " energy points" << std::endl;

        clap.takeDamage(5);
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getHitPoints() << RES " hp" << std::endl;
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getEnergyPoints() << RES " energy points" << std::endl;

        clap.beRepaired(5);
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getHitPoints() << RES " hp" << std::endl;
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getEnergyPoints() << RES " energy points" << std::endl;

        for (int i = 0; i < 10; ++i) {
            clap.attack("Dummy");
        }
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getEnergyPoints() << RES " energy points" << std::endl;

        clap.beRepaired(5);
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getEnergyPoints() << RES " energy points" << std::endl;
    }

    std::cout << BLUE "\nEnergy points and beRepaired method" RES << std::endl;
    {
        ClapTrap clap("Foo");
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getHitPoints() << RES " hp" << std::endl;
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getEnergyPoints() << RES " energy points" << std::endl;
        
        clap.takeDamage(10);
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getHitPoints() << RES " hp" << std::endl;

        clap.attack("Dummy");

        clap.beRepaired(42);
        std::cout << YELLOW "ClapTrap " << BLUE << clap.getName() << RES " has " GREEN << clap.getHitPoints() << RES " hp" << std::endl;
    }

    return 0;
}
