#ifndef SPAN_HPP
#define SPAN_HPP

#define BLUE "\x1b[38;5;25m"
#define CYAN "\x1b[38;5;51m"
#define YELLOW "\x1b[38;5;220m"
#define RED "\x1b[38;5;196m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>

class Span {
    private:
        std::vector<int> span;
        unsigned int     N;

    public:
        Span(void);
        Span(Span const &obj);
        ~Span(void);
        Span &operator=(Span const &rhs);

        Span(unsigned int N);

        void addNumber(int value);

        template <typename T>
        void addNumber(T begin, T end) {
            if (this->span.size() + std::distance(begin, end) > this->N) {
                throw std::length_error("Provided range will exceed Span's capacity");
            }
            this->span.insert(this->span.end(), begin, end);
        }

        int shortestSpan(void) const;
        int longestSpan(void) const;
        
        size_t       size(void) const;
        unsigned int capacity(void) const;
};

#endif
