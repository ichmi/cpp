#include "Zombie.hpp"

int main() {
    Zombie stackedZombie("Stacked zombie");
    stackedZombie.announce();

    {
        Zombie localStackedZombie("Local stacked zombie");
        localStackedZombie.announce();
    }

    Zombie *heapZombie = NULL;
    heapZombie = newZombie("Heap zombie");
    heapZombie->announce();
    delete heapZombie;

    randomChump("Random zombie");

    return 0;
}
