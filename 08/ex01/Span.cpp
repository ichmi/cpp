#include "Span.hpp"

Span::Span(void) : span(std::vector<int>(0)), N(0) {}

Span::Span(Span const &obj) : span(std::vector<int>(0)), N(0) {
    *this = obj;
}

Span::~Span(void) {}

Span &Span::operator=(Span const &rhs) {
    this->span = std::vector<int>(rhs.span);
    this->N = rhs.N;

    return *this;
}

Span::Span(unsigned int N) : span(std::vector<int>(0)), N(N) {}

void Span::addNumber(int value) {
    if (this->span.size() >= this->N) {
        throw std::length_error("Span has reached its capacity");
    }

    this->span.push_back(value);
}

int Span::shortestSpan(void) const {
    if (this->span.size() < 2) {
        throw std::runtime_error("Span doesnt have enough elements to query");
    }

    std::vector<int> __span(this->span);

    std::vector<int>::iterator begin = __span.begin();
    std::vector<int>::iterator end = __span.end();

    std::sort(begin, end);
    int shortest = __span[1] - __span[0];

    int diff;
    for (size_t i = 1; i < __span.size(); ++i) {
        diff = std::abs(__span[i] - __span[i - 1]);
        if (diff == 0) {
            continue ;
        }
        if (diff < shortest) {
            shortest = diff;
        }
    }

    return shortest;
}

int Span::longestSpan(void) const {
    if (this->span.size() < 2) {
        throw std::runtime_error("Span doesnt have enough elements to query");
    }

    std::vector<int>::const_iterator begin = this->span.begin();
    std::vector<int>::const_iterator end = this->span.end();

    int min = *std::min_element(begin, end);
    int max = *std::max_element(begin, end);

    return max - min;
}

size_t Span::size(void) const {
    return this->span.size();
}

unsigned int Span::capacity(void) const {
    return this->N;
}
