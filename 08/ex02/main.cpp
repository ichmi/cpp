#include "MutantStack.hpp"

int main(void) {
    std::cout << BLUE "42 subject example (MutantStack)" RES << std::endl;
    {
        MutantStack<int> mstack;

        mstack.push(5);

        mstack.push(17);
        std::cout << YELLOW << mstack.top() << RES << std::endl;

        mstack.pop();
        std::cout << GREEN << mstack.size() << RES << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it  = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);
    }

    std::cout << BLUE "\nComparing with std::list<int>" RES << std::endl;
    {
        std::list<int> lst;

        lst.push_back(5);

        lst.push_back(17);
        std::cout << YELLOW << lst.back() << RES << std::endl;

        lst.pop_back();
        std::cout << GREEN << lst.size() << RES << std::endl;

        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);

        std::list<int>::iterator end = lst.end();
        for (std::list<int>::iterator it = lst.begin(); it != end; ++it) {
            std::cout << *it << std::endl;
        }
    }

    return 0;
}
