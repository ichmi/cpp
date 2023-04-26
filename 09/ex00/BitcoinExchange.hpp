#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define BLUE "\x1b[38;5;25m"
#define CYAN "\x1b[38;5;51m"
#define YELLOW "\x1b[38;5;220m"
#define PURPLE "\x1b[38;5;162m"
#define RED "\x1b[38;5;196m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>
#include <algorithm>
#include <map>
#include <memory>
#include <fstream>
#include <sstream>
#include <iomanip>

class BitcoinExchange {
    private:
        BitcoinExchange(void);

        std::map<std::string, double> btcPriceMap;
        bool isValidDate(std::string const &date) const;

    public:
        BitcoinExchange(BitcoinExchange const &obj);
        ~BitcoinExchange(void);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);

        BitcoinExchange(std::string const &dbFile);

        void exchange(std::string const &infile) const;
};

#endif
