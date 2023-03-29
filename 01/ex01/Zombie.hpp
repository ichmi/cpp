#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
   private:
    std::string name;

   public:
    Zombie(void);
    Zombie(std::string name);

    ~Zombie();

    void announce(void);
    void setName(std::string value);
};

Zombie* zombieHorde(int N, std::string name);

#endif