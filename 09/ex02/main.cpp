#include "PmergeMe.hpp"
#include <bits/types/clock_t.h>
#include <iomanip>
#include <ios>
#include <stdexcept>

std::vector<int> initVSequence(int ac, char **av) {
    std::list<int> lst;
    for (int i = 1; i < ac; ++i) {
        std::string const arg(av[i]);
        for (std::size_t i = 0; i < arg.size(); ++i) {
            if (arg[i] == '-' || arg[i] == '+') {
                continue ;
            }
            if (!std::isdigit(arg[i])) {
                throw std::invalid_argument("Invalid argument");
            }
        }
        int value = std::atoi(arg.c_str());
        if (value < 0) {
            throw std::invalid_argument("Negative value");
        }
        lst.push_back(value);
    }

    return std::vector<int>(lst.begin(), lst.end());
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << RED "- " GRAY "Error: Invalid number of arguments" RES << std::endl;
        return 1;
    }

    try {
        std::vector<int> sequence = initVSequence(ac, av);

        std::cout << "Before: ";
        PmergeMe::displaySequence(sequence);

        clock_t start = clock();

        PmergeMe::sort(sequence);

        clock_t end = clock();
        double timestamp = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        std::cout << "After:  ";
        PmergeMe::displaySequence(sequence);

        std::cout << std::fixed << std::setprecision(8);
        std::cout << GRAY "Time to process a range of " YELLOW << (ac - 1) << GRAY " elements with std::vector: " GREEN << timestamp << GRAY "µs" RES << std::endl;


    } catch (std::exception const &e) {
        std::cerr << RED "- Error: " GRAY << e.what() << RES << std::endl;
        return 1;
    }

    return 0;
}
