#include "PmergeMe.hpp"

void initSequences(int ac, char **av, std::vector<int> &vec, std::deque<int> &deq);
bool isSorted(std::vector<int> &vec);
bool isSorted(std::deque<int> &deq);

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << RED "- " GRAY "Error: " RED "Invalid number of arguments" RES << std::endl;
        return 1;
    }

	std::vector<int> vec;
	std::deque<int>  deq;

    try {
        initSequences(ac, av, vec, deq);
    } catch (std::exception const &e) {
        std::cerr << RED "- " GRAY "Error: " RED << e.what() << RES << std::endl;
        return 1;
    }

    std::cout << std::fixed << std::setprecision(8);

    std::cout << BLUE "using std::vector<" CYAN "int" BLUE ">" RES << std::endl;
    {
        PmergeMe mmVector;
        std::cout << YELLOW "Before: ";
        mmVector.displaySequence(vec);

        clock_t start = clock();
        mmVector.sort(vec);
        clock_t end = clock();
        double timestamp = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        std::cout << YELLOW "After:  ";
        mmVector.displaySequence(vec);
        std::cout << GRAY "Time to process a range of " YELLOW << (ac - 1) << GRAY " elements with " BLUE "std::vector" GRAY ": " GREEN << timestamp << GRAY "µs" RES << std::endl;
    }

    std::cout << BLUE "\nusing std::deque<" CYAN "int" BLUE ">" RES << std::endl;
    {
        PmergeMe mmDeque;
        std::cout << YELLOW "Before: ";
        mmDeque.displaySequence(deq);

        clock_t start = clock();
        mmDeque.sort(deq);
        clock_t end = clock();
        double timestamp = static_cast<double>(end - start) / CLOCKS_PER_SEC;

        std::cout << YELLOW "After:  ";
        mmDeque.displaySequence(deq);
        std::cout << GRAY "Time to process a range of " YELLOW << (ac - 1) << GRAY " elements with " BLUE "std::deque" GRAY ":  " GREEN << timestamp << GRAY "µs" RES << std::endl;
    }

    std::cout << std::endl;
    {
        std::vector<int> vec;
        std::deque<int>  deq;

        try {
            initSequences(ac, av, vec, deq);
        } catch (std::exception const &e) {
            std::cerr << RED "- " GRAY "Error: " RED << e.what() << RES << std::endl;
            return 1;
        }

        std::cout << BLUE "\nusing std::sort<" CYAN "std::vector<int>" BLUE ">" RES << std::endl;
        {
            std::cout << GRAY "Sorted: " << (isSorted(vec)? GREEN "OK": RED "KO") << RES << std::endl;
            clock_t start = clock();

            std::sort(vec.begin(), vec.end());

            clock_t end = clock();
            double timestamp = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            std::cout << GRAY "Algorithm: " YELLOW << (ac - 1) << GRAY " elements with " BLUE "std::sort<std::vector>" GRAY ": " GREEN << timestamp << GRAY "µs" RES << std::endl;
            std::cout << GRAY "Sorted: " << (isSorted(vec)? GREEN "OK": RED "KO") << RES << std::endl;
            
        }

        std::cout << BLUE "\nusing std::sort<" CYAN "std::deque<int>" BLUE ">" RES << std::endl;
        {
            std::cout << GRAY "Sorted: " << (isSorted(deq)? GREEN "OK": RED "KO") << RES << std::endl;
            clock_t start = clock();

            std::sort(deq.begin(), deq.end());

            clock_t end = clock();
            double timestamp = static_cast<double>(end - start) / CLOCKS_PER_SEC;
            std::cout << GRAY "Algorithm: " YELLOW << (ac - 1) << GRAY " elements with " BLUE "std::sort<std::deque>" GRAY ":  " GREEN << timestamp << GRAY "µs" RES << std::endl;
            std::cout << GRAY "Sorted: " << (isSorted(deq)? GREEN "OK": RED "KO") << RES << std::endl;
        }
    }

    return 0;
}

void initSequences(int ac, char **av, std::vector<int> &vec, std::deque<int> &deq) {
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
            throw std::invalid_argument("Negative argument");
        }
        vec.push_back(value);
        deq.push_back(value);
    }
}

bool isSorted(std::vector<int> &vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }
    return true;
}

bool isSorted(std::deque<int> &deq) {
    for (size_t i = 1; i < deq.size(); ++i) {
        if (deq[i] < deq[i - 1]) {
            return false;
        }
    }
    return true;
}
