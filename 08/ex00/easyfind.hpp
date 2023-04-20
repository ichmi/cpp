#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#define BLUE "\x1b[38;5;25m"
#define CYAN "\x1b[38;5;51m"
#define YELLOW "\x1b[38;5;220m"
#define RED "\x1b[38;5;196m"
#define GRAY "\x1b[38;5;8m"
#define RES "\x1b[0m"

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <queue>

template <typename T>
typename T::iterator easyfind(T &container, int const value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end()) {
        throw std::runtime_error("value not found in container");
    }

    return it;
}

template <typename T>
typename T::const_iterator easyfind(T const &container, int const value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end()) {
        throw std::runtime_error("value not found in container");
    }

    return it;
}

#endif
