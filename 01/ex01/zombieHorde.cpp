#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N < 1) {
        std::cout << "You must provide a positive number to instantiate a horde of zombies" << std::endl;
        return NULL;
    }
    if (name.empty()) {
        name = "Generic Zombie";
    }

    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; i++) {
        horde[i].setName(name);
    }

    return horde;
}
