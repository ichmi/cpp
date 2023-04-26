#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) : chunkSize(10) {}

PmergeMe::PmergeMe(PmergeMe const &obj) : chunkSize(10) {
    *this = obj;
}

PmergeMe::~PmergeMe(void) {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
    (void) rhs;
    return *this;
}

void PmergeMe::sort(std::vector<int> &vec) {
    vit l = vec.begin();
    vit r = vec.end();

    this->sort(vec, l, r);
}

void PmergeMe::sort(std::vector<int> &vec, vit l, vit r) {
    if (std::distance(l, r) <= this->chunkSize) {
        for (vit it = l + 1; it != r; ++it) {
            int k = *it;
            vit j = it;
            while (j != l && *(j - 1) > k) {
                *j = *(j - 1);
                --j;
            }
            *j = k;
        }
    } else {
        vit m = l;
        std::advance(m, std::distance(l, r) / 2);

        this->sort(vec, l, m);
        this->sort(vec, m, r);
        this->mergeVec(l, m, r);
    }
}

void PmergeMe::mergeVec(vit l, vit m, vit r) {
    std::vector<int> vector(std::distance(l, r));

    vit i = l;
    vit j = m;
    int  k = 0;
    while (i != m && j != r) {
        if (*i <= *j) {
            vector[k++] = *(i++);
        } else {
            vector[k++] = *(j++);
        }
    }

    while (i != m) {
        vector[k++] = *(i++);
    }
    while (j != r) {
        vector[k++] = *(j++);
    }

    for (k = 0, i = l; i != r; ++i, ++k) {
        *i = vector[k];
    }
}

void PmergeMe::displaySequence(std::vector<int> const &vec) {
    int const threshold = 10;

    std::size_t maxWidth = 0;

    typedef std::vector<int>::const_iterator cit;
    for (cit it = vec.begin(); it != vec.end(); ++it) {
        std::stringstream ss;
        ss << *it;

        std::string const number = ss.str();
        if (number.size() > maxWidth) {
            maxWidth = number.size();
        }
    }

    std::size_t count = 0;
    for (cit it = vec.begin(); it != vec.end(); ++it) {
        if (count == threshold) {
            std::cout << GRAY "[...]" RES;
            break ;
        }

        std::stringstream ss;
        ss << *it;

        std::string const number = ss.str();
        std::cout << CYAN << std::setw(maxWidth) << number << RES;
        if (std::distance(vec.begin(), it) < static_cast<int>(vec.size()) - 1) {
            std::cout << " ";
        }
        count++;
    }

    std::cout << std::endl;
}

void PmergeMe::sort(std::deque<int> &deq) {
    dit l = deq.begin();
    dit r = deq.end();

    this->sort(deq, l, r);
}

void PmergeMe::sort(std::deque<int> &deq, dit l, dit r) {
    if (std::distance(l, r) <= this->chunkSize) {
        for (dit it = l + 1; it != r; ++it) {
            int k = *it;
            dit j = it;
            while (j != l && *(j - 1) > k) {
                *j = *(j - 1);
                --j;
            }
            *j = k;
        }
    } else {
        dit m = l;
        std::advance(m, std::distance(l, r) / 2);

        this->sort(deq, l, m);
        this->sort(deq, m, r);
        this->mergeDeq(l, m, r);
    }
}

void PmergeMe::mergeDeq(dit l, dit m, dit r) {
    std::deque<int> temp(std::distance(l, r));

    dit i = l;
    dit j = m;
    int  k = 0;
    while (i != m && j != r) {
        if (*i <= *j) {
            temp[k++] = *(i++);
        } else {
            temp[k++] = *(j++);
        }
    }

    while (i != m) {
        temp[k++] = *(i++);
    }
    while (j != r) {
        temp[k++] = *(j++);
    }

    for (k = 0, i = l; i != r; ++i, ++k) {
        *i = temp[k];
    }
}

void PmergeMe::displaySequence(std::deque<int> const &deq) {
    int const threshold = 10;

    std::size_t maxWidth = 0;

    typedef std::deque<int>::const_iterator cit;
    for (cit it = deq.begin(); it != deq.end(); ++it) {
        std::stringstream ss;
        ss << *it;

        std::string const number = ss.str();
        if (number.size() > maxWidth) {
            maxWidth = number.size();
        }
    }

    std::size_t count = 0;
    for (cit it = deq.begin(); it != deq.end(); ++it) {
        if (count == threshold) {
            std::cout << GRAY "[...]" RES;
            break ;
        }

        std::stringstream ss;
        ss << *it;

        std::string const number = ss.str();
        std::cout << CYAN << std::setw(maxWidth) << number << RES;
        if (std::distance(deq.begin(), it) < static_cast<int>(deq.size()) - 1) {
            std::cout << " ";
        }
        count++;
    }
    std::cout << std::endl;
}
