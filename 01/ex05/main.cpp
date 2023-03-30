#include "Harl.hpp"

int main(int ac, char **av) {
    Harl harl;

    if (ac > 1) {
        for (int i = 1; av[i]; i++) {
            harl.complain(av[i]);
            if (av[i + 1]) {
                std::cout << std::endl;
            }
        }
        return 0;
    }

    std::cout << BLUE "Testing with lowercase levels" RES << std::endl;
    harl.complain("debug");
    std::cout << std::endl;
    harl.complain("info");
    std::cout << std::endl;
    harl.complain("warning");
    std::cout << std::endl;
    harl.complain("error");
    std::cout << std::endl << std::endl;

    std::cout << BLUE "Testing with uppercase levels" RES << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl << std::endl;

    std::cout << BLUE "Testing invalid level options" RES << std::endl;
    harl.complain("foo");
    std::cout << std::endl;
    harl.complain("");

    return 0;
}
