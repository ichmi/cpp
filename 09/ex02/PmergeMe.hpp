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
#include <deque>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <algorithm>

class PmergeMe {
    private:
        int const chunkSize;

        typedef std::vector<int>::iterator vit;
        void sort(std::vector<int> &vec, vit l, vit r);
        void mergeVec(vit l, vit m, vit r);

        typedef std::deque<int>::iterator  dit;
        void sort(std::deque<int> &deq, dit l, dit r);
        void mergeDeq(dit l, dit m, dit r);

    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const &obj);
        ~PmergeMe(void);
        PmergeMe &operator=(PmergeMe const &rhs);

        void sort(std::vector<int> &vec);
        void displaySequence(std::vector<int> const &vec);

        void sort(std::deque<int> &deq);
        void displaySequence(std::deque<int> const &deq);
};

#endif
