#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>
#include <iterator>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack(void);
        MutantStack(MutantStack const &obj);
        ~MutantStack(void);
        MutantStack &operator=(MutantStack const &rhs);

        typedef typename std::stack<T>::container_type ct;

        typedef typename ct::iterator                  iterator;
        typedef typename ct::const_iterator            const_iterator;
        typedef typename ct::reverse_iterator          reverse_iterator;
        typedef typename ct::const_reverse_iterator    const_reverse_iterator;

        iterator               begin(void);
        const_iterator         begin(void) const;
        iterator               end(void);
        const_iterator         end(void) const;

        reverse_iterator       rbegin(void);
        const_reverse_iterator rbegin(void) const;
        reverse_iterator       rend(void);
        const_reverse_iterator rend(void) const;

};

#include "MutantStack.tpp"

#endif
