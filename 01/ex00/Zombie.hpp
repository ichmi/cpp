#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define RES "\x1b[0m"

#include <iostream>

class Zombie {
   private:
    std::string name;

   public:
    Zombie(void);
    Zombie(std::string name);

    ~Zombie();

    void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
