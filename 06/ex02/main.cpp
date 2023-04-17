#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);

void   identify(Base* p);
void   identify(Base& p);

int main(void) {
    std::srand(time(NULL));

    std::cout << BLUE "Identify real type via dynamic_cast operator (pointer)" RES << std::endl;
    Base *base = generate();
    identify(base);

    std::cout << BLUE "\nIdentify real type via dynamic_cast operator (reference)" RES << std::endl;
    identify(*base);

    delete base;

    std::cout << BLUE "\nInvalid pointer to X instance" RES << std::endl;
    class X : public Base {};
    Base px = X();
    identify(&px);

    std::cout << BLUE "\nInvalid reference to Y instance" RES << std::endl;
    class Y : public Base {};
    Base py = Y();
    identify(py);

    return 0;
}

Base * generate(void) {
    switch (std::rand() % 3) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            return NULL;
    }
}

void identify(Base* p) {
    A *pa = dynamic_cast<A*>(p);
    if (pa) {
        std::cout << GREEN "+ " GRAY "Pointer points to an instance of class " YELLOW "A" RES << std::endl;
        return ;
    } 
    
    B *pb = dynamic_cast<B*>(p);
    if (pb) {
        std::cout << GREEN "+ " GRAY "Pointer points to an instance of class " YELLOW "B" RES << std::endl;
        return ;
    }

    C *pc = dynamic_cast<C*>(p);
    if (pc) {
        std::cout << GREEN "+ " GRAY "Pointer points to an instance of class " YELLOW "C" RES << std::endl;
        return ;
    }

    std::cerr << RED "- " GRAY "Cant cast to " YELLOW "A" GRAY ", " YELLOW "B" GRAY ", or " YELLOW "C" RES << std::endl;
}

void identify(Base& p) {
    try {
        A &ra = dynamic_cast<A&>(p);
        if (&ra == &p) {
            std::cout << GREEN "+ " GRAY "Reference of type " YELLOW "A" RES << std::endl;
            return ;
        }
    } catch (std::exception &e) {
        std::cerr << RED "- " GRAY "Error while casting &Base to &A: " RED << e.what() << RES << std::endl;
    }

    try {
        B &rb = dynamic_cast<B&>(p);
        if (&rb == &p) {
            std::cout << GREEN "+ " GRAY "Reference of type " YELLOW "B" RES << std::endl;
            return ;
        }
    } catch (std::exception &e) {
        std::cerr << RED "- " GRAY "Error while casting &Base to &B: " RED << e.what() << RES << std::endl;
    }

    try {
        C &rc = dynamic_cast<C&>(p);
        if (&rc == &p) {
            std::cout << GREEN "+ " GRAY "Reference of type " YELLOW "C" RES << std::endl;
            return ;
        }
    } catch (std::exception &e) {
        std::cerr << RED "- " GRAY "Error while casting &Base to &C: " RED << e.what() << RES << std::endl;
    }

    std::cerr << RED "- " GRAY "Cant cast to " YELLOW "A" GRAY ", " YELLOW "B" GRAY ", or " YELLOW "C" RES << std::endl;
}
