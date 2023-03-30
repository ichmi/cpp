#include "Zombie.hpp"

int main() {
	std::cout << BLUE "Main stacked Zombie test:" RES << std::endl;
    Zombie stackedZombie("Main zombie");
    stackedZombie.announce();

	std::cout << std::endl << BLUE "Local stacked zombies test:" RES << std::endl;
    {
        Zombie localStackedZombie("Local stacked zombie");
        localStackedZombie.announce();
    }
	{
        Zombie localStackedZombie("");
        localStackedZombie.announce();
    }

	std::cout << std::endl << BLUE "Dynamically allocated zombies test:" RES << std::endl;
    Zombie *heapZombie = NULL;
    heapZombie = newZombie("Heap zombie");
    heapZombie->announce();
    delete heapZombie;

	Zombie *heapGenericZombie = NULL;
    heapGenericZombie = newZombie("");
    heapGenericZombie->announce();
    delete heapGenericZombie;

	std::cout << std::endl << BLUE "RandomChump function test:" RES << std::endl;
    randomChump("Random zombie");
    randomChump("");

	std::cout << std::endl << BLUE "Main Zombie is going to die now!" RES << std::endl;
    return 0;
}
