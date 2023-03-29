#include "Zombie.hpp"

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define RES "\x1b[0m"

static void spawnHordeLevel(int N, std::string zombieNames, std::string level) {
    if (level.empty()) {
        std::cout << BLUE << "Some zombie horde" << RES << std::endl;
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
    spawnHordeLevel(-1, "Baz", "1st invalid");
    spawnHordeLevel(0, "Baz", "2nd invalid");
    spawnHordeLevel(5, "", "3rd invalid");

    spawnHordeLevel(1, "Foo", "First zombie horde");
    spawnHordeLevel(5, "Bar", "Second zombie horde");
    spawnHordeLevel(10, "Baz", "Third zombie horde");
    spawnHordeLevel(256, "Dummy", "Fourth zombie horde");

    return 0;
}
