#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

#define RED "\x1b[38;5;10m"
#define BLUE "\x1b[38;5;25m"
#define CYAN "\x1b[38;5;37m"
#define YELLOW "\x1b[38;5;220m"
#define RES "\x1b[0m"

int main() {
    std::cout << BLUE << "Testcases with Human A" << RES << std::endl;
    {
        Weapon weapon = Weapon("");
        HumanA foo("Foo", weapon);
        foo.attack();
    }
    {
        Weapon weapon = Weapon("Pick axe");
        HumanA foo("", weapon);
        foo.attack();
    }
    {
        Weapon weapon = Weapon("");
        HumanA foo("", weapon);
        foo.attack();
    }

    std::cout << std::endl << BLUE << "Testcases with Human B" << RES << std::endl;
    {
        HumanB foo("Bar");
        foo.attack();
    }
    {
        Weapon weapon = Weapon("");
        HumanB foo("Bar");
        foo.setWeapon(weapon);
        foo.attack();
    }
    {
        Weapon weapon = Weapon("Axe");
        HumanB foo("");
        foo.setWeapon(weapon);
        foo.attack();
    }
    {
        Weapon weapon = Weapon("");
        HumanB foo("");
        foo.setWeapon(weapon);
        foo.attack();
    }


    std::cout << std::endl << BLUE << "42 intranet subject example" << RES << std::endl;
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }


    std::cout << std::endl << BLUE << "Now, a hero fights for his life inside a cave" << RES << std::endl;

    Weapon sword = Weapon(YELLOW "Gold Sword" RES);
    Weapon bow = Weapon(RED "Bow" RES);

    HumanB sieg("Matilda");
    sieg.attack();

    sieg.setWeapon(sword);
    sieg.attack();
    std::cout << std::endl << BLUE << "After killing that zombie, she found some Diamonds and start crafting a new weapon..." << RES << std::endl;
    sword.setType(CYAN "Diamond Sword" RES);
    sieg.attack();

    std::cout << std::endl << BLUE << "Now she change its weapon quickly in order to shot that dummy zombie from before" << RES << std::endl;
    sieg.setWeapon(bow);
    sieg.attack();

    std::cout << std::endl << BLUE << "That bow sucks, so she decided to change it again and..." << RES << std::endl;
    bow.setType(RED "Awesome Long bow that you could never miss a single shot..." RES);
    sieg.attack();

    std::cout << std::endl << BLUE << "Swap its weapons once, getting its Diamond Sword" << RES << std::endl;
    sieg.setWeapon(sword);
    sieg.attack();

    std::cout << std::endl;
    
    return 0;
}
