#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &obj) {
    *this = obj;
}

PmergeMe::~PmergeMe(void) {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    (void) rhs;
    return *this;
}

