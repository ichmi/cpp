#include <iostream>

static void fillUpperBuffer(std::string str, std::string &buff) {
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        buff += static_cast<char>(std::toupper(*it));
    }
}

int main(int ac, char **av) {
    if (ac == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    std::string buff;

    av++;
    while (*av) {
        const std::string arg = *av;
        fillUpperBuffer(arg, buff);
        av++;
    }
    std::cout << buff << std::endl;

    return 0;
}
