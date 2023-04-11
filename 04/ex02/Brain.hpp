#ifndef BRAIN_HPP
#define BRAIN_HPP

#define PINK "\x1b[38;5;213m"
#define RES "\x1b[0m"

#include <iostream>
#include <cstdlib>

#define NUM_IDEAS 100

class Brain {
    private:
        std::string ideas[NUM_IDEAS];

    public:
        Brain(void);
        Brain(Brain const &brainObj);
        ~Brain(void);
        Brain &operator=(Brain const &rhs);

        std::string getIdea(int const i) const;
};

#endif
