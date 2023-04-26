#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << RED "- " GRAY "Error: missing input data file" RES << std::endl;
        return 1;
    }

    std::string const dbFile = "data.csv";
    std::string const infile = av[1];

    std::cout << BLUE "42 subject example" RES << std::endl;
    {
        try {
            BitcoinExchange btc(dbFile);
            btc.exchange(infile);
        } catch (std::exception const &e) {
            std::cerr << RED << e.what() << RES << std::endl;
        }
    }

    return 0;
}
