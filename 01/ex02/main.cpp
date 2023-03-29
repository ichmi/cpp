#include <iostream>

#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define RES "\x1b[0m"

int main() {
    std::string str = "HI THIS IS BRAIN";

    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << BLUE << "Addresses:" << RES << std::endl;
    std::cout << "  str(" << YELLOW << &str << RES << ")" << std::endl;
    std::cout << "  ptr(" << stringPTR << ")" << std::endl;
    std::cout << "  ref(" << &stringREF << ")" << std::endl << std::endl;

    std::cout << BLUE << "Values:" << RES << std::endl;
    std::cout << "  str(" << str << ")" << std::endl;
    std::cout << "  ptr(" << *stringPTR << ")" << std::endl;
    std::cout << "  ref(" << stringREF << ")" << std::endl;

    return 0;
}
