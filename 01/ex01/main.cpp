#include "Zombie.hpp"

static void spawnHordeLevel(int N, std::string zombieNames, std::string level) {
    if (level.empty()) {
        std::cout << BLUE "Some zombie horde" RES << std::endl;
    } else {
        std::cout << BLUE << level << RES << std::endl;
    }

    int const hordeNumber = N;
    int count = 0;
    Zombie *horde = zombieHorde(hordeNumber, zombieNames);

    if (horde) {
        for (int i = 0; i < hordeNumber; i++) {
            horde[i].announce();
            count++;
        }
        delete[] horde;
    }
    std::cout << "Total number of zombies: " << YELLOW << count << RES << std::endl << std::endl;
}

int main() {
    spawnHordeLevel(-1, "Baz", "Negative value");
    spawnHordeLevel(0, "Baz", "Zero value");

    spawnHordeLevel(1, "Foo", "1 zombie");
    spawnHordeLevel(5, "Bar", "5 zombies");
    spawnHordeLevel(10, "Baz", "10 zombies");
    spawnHordeLevel(256, "Dummy", "256 zombies");

    spawnHordeLevel(7, "", "Generic zombie horde of 7");

    return 0;
}
