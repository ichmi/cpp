#include "Harl.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << _ERROR "invalid number of arguments" << std::endl;
        return 1;
    }

    Harl harl;
    harl.complain(av[1]);

    return 0;
}
