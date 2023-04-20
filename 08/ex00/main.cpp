#include "easyfind.hpp"

int main(void) {
    int const tab[]   = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    size_t const tabSize = sizeof(tab) / sizeof(tab[0]);

    std::vector<int> vec;
    std::deque<int>  deq;
    std::list<int>   lst;

    for (size_t i = 0; i < tabSize; ++i) {
        vec.push_back(tab[i]);
        deq.push_back(tab[i]);
        lst.push_back(tab[i]);
    }

    std::cout << BLUE "vector<" CYAN "int" BLUE "> iteration" RES << std::endl;
    {
        std::vector<int>::iterator it;

        try {
            it = easyfind(vec, 8);
            int const dist = std::distance(vec.begin(), it);
            std::cout << YELLOW "vector: " GRAY "found at position " YELLOW << dist << RES << std::endl;
        } catch (std::exception const &e) {
            std::cerr << YELLOW "vector: " RED << e.what() << RES << std::endl;
        }

        try {
            it = easyfind(vec, -42);
        } catch (std::exception const &e) {
            std::cerr << YELLOW "vector: " RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\ndeque<" CYAN "int" BLUE "> iteration" RES << std::endl;
    {
        std::deque<int>::iterator it;

        try {
            it = easyfind(deq, 8);
            int const dist = std::distance(deq.begin(), it);
            std::cout << YELLOW "deque: " GRAY "found at position " YELLOW << dist << RES << std::endl;
        } catch (std::exception const &e) {
            std::cerr << YELLOW "deque: " RED << e.what() << RES << std::endl;
        }

        try {
            it = easyfind(deq, -42);
        } catch (std::exception const &e) {
            std::cerr << YELLOW "deque: " RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nlist<" CYAN "int" BLUE "> iteration" RES << std::endl;
    {
        std::list<int>::iterator it;

        try {
            it = easyfind(lst, 8);
            int const dist = std::distance(lst.begin(), it);
            std::cout << YELLOW "list: " GRAY "found at position " YELLOW << dist << RES << std::endl;
        } catch (std::exception const &e) {
            std::cerr << YELLOW "list: " RED << e.what() << RES << std::endl;
        }

        try {
            it = easyfind(lst, -42);
        } catch (std::exception const &e) {
            std::cerr << YELLOW "list: " RED << e.what() << RES << std::endl;
        }
    }


    int const fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    size_t const fibSize = sizeof(fib) / sizeof(fib[0]);
    const std::vector<int> constVec(fib, fib + fibSize);
    const std::deque<int>  constDeq(fib, fib + fibSize);
    const std::list<int>   constLst(fib, fib + fibSize);

    std::cout << BLUE "\nconst vector<" CYAN "int" BLUE "> iteration" RES << std::endl;
    {
        std::vector<int>::const_iterator it;

        try {
            it = easyfind(constVec, 8);
            int const dist = std::distance(constVec.begin(), it);
            std::cout << CYAN "const vector: " GRAY "found at position " YELLOW << dist << RES << std::endl;
        } catch (std::exception const &e) {
            std::cerr << CYAN "const vector: " RED << e.what() << RES << std::endl;
        }

        try {
            it = easyfind(constVec, -42);
        } catch (std::exception const &e) {
            std::cerr << CYAN "const vector: " RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nconst deque<" CYAN "int" BLUE "> iteration" RES << std::endl;
    {
        std::deque<int>::const_iterator it;

        try {
            it = easyfind(constDeq, 8);
            int const dist = std::distance(constDeq.begin(), it);
            std::cout << CYAN "const deque: " GRAY "found at position " YELLOW << dist << RES << std::endl;
        } catch (std::exception const &e) {
            std::cerr << CYAN "const deque: " RED << e.what() << RES << std::endl;
        }

        try {
            it = easyfind(constDeq, -42);
        } catch (std::exception const &e) {
            std::cerr << CYAN "const deque: " RED << e.what() << RES << std::endl;
        }
    }

    std::cout << BLUE "\nconst list<" CYAN "int" BLUE "> iteration" RES << std::endl;
    {
        std::list<int>::const_iterator it;

        try {
            it = easyfind(constLst, 8);
            int const dist = std::distance(constLst.begin(), it);
            std::cout << CYAN "const list: " GRAY "found at position " YELLOW << dist << RES << std::endl;
        } catch (std::exception const &e) {
            std::cerr << CYAN "const list: " RED << e.what() << RES << std::endl;
        }

        try {
            it = easyfind(constLst, -42);
        } catch (std::exception const &e) {
            std::cerr << CYAN "const list: " RED << e.what() << RES << std::endl;
        }
    }

    return 0;
}
