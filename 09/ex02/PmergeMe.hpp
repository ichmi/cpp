#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define RED "\x1b[38;5;196m"
#define BLUE "\x1b[38;5;25m"
#define CYAN "\x1b[38;5;51m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>

class PmergeMe {
    private:

    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const &obj);
        ~PmergeMe(void);
        PmergeMe &operator=(PmergeMe const &rhs);
};

#endif
