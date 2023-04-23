#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj) {
    *this = obj;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
    this->btcPriceMap = rhs.btcPriceMap;

    return *this;
}

BitcoinExchange::BitcoinExchange(std::string const &dbFile) {
    std::auto_ptr<std::ifstream> ifs(new std::ifstream(dbFile.c_str()));
    if (ifs->fail()) {
        std::cerr << RED "- " GRAY "Error: could not open database file" << RED << std::endl;
    }

    std::string row;
    std::getline(*ifs, row);

    while (std::getline(*ifs, row)) {
        int commaCount = 0;
        for (std::string::iterator it = row.begin(); it != row.end(); ++it) {
            if (*it == ',') {
                commaCount++;
            }
        }

        if (commaCount != 1) {
            throw std::invalid_argument("Bad database file: Delimeter");
        }

        std::istringstream iss(row);

        std::string date;
        double priceRate;

        std::getline(iss, date, ',');
        date.erase(0, date.find_first_not_of(" "));
        date.erase(date.find_last_not_of(" ") + 1);

        if (date.empty()) {
            throw std::invalid_argument("Bad database file: Empty date");
        }

        iss >> priceRate;
        if (iss.fail() || priceRate < 0) {
            throw std::invalid_argument("Bad database file: Invalid value");
        }

        if (!this->isValidDate(date)) {
            throw std::invalid_argument("Bad database file: Invalid date format");
        }

        btcPriceMap.insert(std::make_pair(date, priceRate));
    }
}


bool BitcoinExchange::isValidDate(std::string const &date) const {
    if (date.size() != 10) {
        return false;
    }

    if (date[4] != '-' || date[7] != '-') {
        return false;
    }

    std::string const yearStr = date.substr(0, 4);
    std::string const monthStr = date.substr(5, 2);
    std::string const dayStr = date.substr(8, 2);

    bool isDigit = true;
    for (std::size_t i = 0; i < yearStr.size(); ++i) {
        if (!std::isdigit(yearStr[i])) {
            isDigit = false;
        }
    }

    for (std::size_t i = 0; i < monthStr.size(); ++i) {
        if (!std::isdigit(monthStr[i])) {
            isDigit = false;
        }
    }

    for (std::size_t i = 0; i < dayStr.size(); ++i) {
        if (!std::isdigit(dayStr[i])) {
            isDigit = false;
        }
    }

    if (!isDigit) {
        return false;
    }

    int month = 1;
    int day = 1;
    if (monthStr == "00") {
        month = 0;
    }
    if (dayStr == "00") {
        day = 0;
    }

    if (!month || !day) {
        return false;
    }

    int year = std::atoi(yearStr.c_str());
    month = std::atoi(monthStr.c_str());
    day = std::atoi(dayStr.c_str());
    if (!month || !day) {
        return false;
    }

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    if (month == 2) {
        bool const isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 29 || (day > 28 && !isLeapYear)) {
            return false;
        }
    }

    return true;
}

void BitcoinExchange::exchange(std::string const &infile) const {
    std::ifstream ifs(infile.c_str());
    if (ifs.fail()) {
        std::cerr << RED "- " GRAY "Error: could not open data input file" << RED << std::endl;
    }

    std::string row;
    std::getline(ifs, row);

    while (std::getline(ifs, row)) {
        if (row.empty()) {
            continue ;
        }

        int delimeterCount = 0;
        for (std::string::iterator it = row.begin(); it != row.end(); ++it) {
            if (*it == '|') {
                delimeterCount++;
            }
        }

        if (delimeterCount != 1) {
            std::cerr << RED "Bad input: " GRAY "Invalid format" RES << std::endl;
            continue ;
        }

        std::istringstream iss(row);

        std::string queryDate;
        double exchangeRate;

        std::getline(iss, queryDate, '|');
        queryDate.erase(0, queryDate.find_first_not_of(" "));
        queryDate.erase(queryDate.find_last_not_of(" ") + 1);

        if (queryDate.empty()) {
            std::cerr << RED "Bad input: " GRAY "Empty date" << RES << std::endl;
            continue ;
        }

        iss >> exchangeRate;
        if (iss.fail()) {
            std::cerr << RED "Bad input: " GRAY "Invalid value" << RES << std::endl;
            continue ;
        }

        if (exchangeRate > 999) {
            std::cerr << RED "Bad input: " GRAY "Value greater than 999" << RES << std::endl;
            continue ;
        }

        if (exchangeRate < 0) {
            std::cerr << RED "Bad input: " GRAY "Value is not a positive number" << RES << std::endl;
            continue ;
        }

        if (!this->isValidDate(queryDate)) {
            std::cerr << RED "Bad input: " GRAY "Date format" << RES << std::endl;
            continue ;
        }

        std::map<std::string, double>::const_iterator it = btcPriceMap.lower_bound(queryDate);

        if (it != btcPriceMap.begin()) {
            if (it == btcPriceMap.end()) {
                it = this->btcPriceMap.end();
                --it;
            } else if (it->first != queryDate) {
                --it;
            }
        } else {
            std::map<std::string, double>::const_iterator oldestDate = this->btcPriceMap.begin();
            std::cerr << RED "Bad input: " GRAY "Oldest date is " YELLOW << oldestDate->first << RES << std::endl;
            continue ;
        }

        double result = exchangeRate * it->second;
        std::cout << std::fixed << std::setprecision(1) <<
        GRAY << queryDate << " => " CYAN << exchangeRate << GRAY " = " GREEN << result << RES << std::endl;
    }

    ifs.close();
}
