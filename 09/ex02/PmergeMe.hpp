#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define RED "\x1b[38;5;196m"
#define BLUE "\x1b[38;5;25m"
#define CYAN "\x1b[38;5;51m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define YELLOW "\x1b[38;5;220m"
#define RES "\x1b[0m"

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <iomanip>
#include <sstream>

class PmergeMe {
    private:
        PmergeMe(void);

        static int const chunkSize;

        static void sort(std::vector<int> &vec, int const l, int const r);
        static void merge(std::vector<int> &vec, int l, int m, int r);

    public:
        PmergeMe(PmergeMe const &obj);
        ~PmergeMe(void);
        PmergeMe &operator=(PmergeMe const &rhs);


        static void sort(std::vector<int> &sequence);
        static void displaySequence(std::vector<int> const &seq);
};

#endif
