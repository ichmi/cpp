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

int const PmergeMe::chunkSize = 10;

void PmergeMe::sort(std::vector<int> &sequence) {
    PmergeMe::sort(sequence, 0, sequence.size() - 1);
}

void PmergeMe::sort(std::vector<int> &vec, int const l, int const r) {
    if (r - l + 1 <= PmergeMe::chunkSize) {
        for (int i = l + 1; i <= r; ++i) {
            int k = vec[i];
            int j = i - 1;
            while (j >= l && vec[j] > k) {
                vec[j + 1] = vec[j];
                --j;
            }
            vec[j + 1] = k;
        }
    } else {
        int m = l + (r - l) / 2;
        PmergeMe::sort(vec, l, m);
        PmergeMe::sort(vec, m + 1, r);
        PmergeMe::merge(vec, l, m, r);
    }
}

void PmergeMe::merge(std::vector<int> &vec, int l, int m, int r) {
    std::vector<int> temp(r - l + 1);

    int i = l;
    int j = m + 1;
    int k = 0;
    while (i <= m && j <= r) {
        if (vec[i] <= vec[j]) {
            temp[k] = vec[i++];
        } else {
            temp[k] = vec[j++];
        }
        k++;
    }

    while (i <= m) {
        temp[k++] = vec[i++];
    }
    while (j <= r) {
        temp[k++] = vec[j++];
    }

    for (int p = 0; p < k; ++p) {
        vec[l + p] = temp[p];
    }
}


void PmergeMe::displaySequence(std::vector<int> const &seq) {
    int const threshold = 10;

    std::size_t maxWidth = 0;

    for (std::size_t i = 0; i < seq.size(); ++i) {
        std::stringstream ss;
        ss << seq[i];

        std::string const number = ss.str();
        if (number.size() > maxWidth) {
            maxWidth = number.size();
        }
    }

    for (std::size_t i = 0; i < seq.size(); ++i) {
        if (i == threshold) {
            std::cout << "[...]";
            break ;
        }

        std::stringstream ss;
        ss << seq[i];

        std::string const number = ss.str();
        std::cout << std::setw(maxWidth) << number;
        if (i < seq.size() - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;
}
