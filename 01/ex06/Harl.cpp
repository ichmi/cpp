#include "Harl.hpp"

#include <cctype>

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::complain(std::string level) {
    if (level.empty()) {
        std::cout << _ERROR "missing log level" << std::endl;
        return;
    }

    std::string upperLevel;
    for (std::string::iterator it = level.begin(); it != level.end(); it++) {
        upperLevel += static_cast<char>(std::toupper(*it));
    }

    int const numberOfOptions = 4;
    std::string options[numberOfOptions] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int levelCode = 0;
    int i = -1;
    while (++i < numberOfOptions && upperLevel != options[i]) {
        levelCode++;
    }

    switch (levelCode) {
        case DEBUG:
            this->debug();
        case INFO:
            this->info();
        case WARNING:
            this->warning();
        case ERROR:
            this->error();
            break;
        default:
            std::cout << "[ " << YELLOW "Probably complaining about insignificant problems" << RES << " ]" << std::endl;
    }
}

void Harl::debug(void) {
    std::cout << "[" YELLOW " DEBUG " RES "]"
              << "\nI love having extra bacon for my \n"
                 "7XL-double-cheese-triple-pickle-specialketchup burger. I "
                 "really do!\n"
              << std::endl;
}

void Harl::info(void) {
    std::cout
        << "[" YELLOW " INFO " RES "]"
        << "\nI cannot believe adding extra bacon costs more money. You \n"
           "didn't put enough bacon in my burger! If you did, I wouldn't \n"
           "be asking for more!\n"
        << std::endl;
}

void Harl::warning(void) {
    std::cout
        << "[" YELLOW " WARNING " RES "]"
        << "\nI think I deserve to have some extra bacon for free. I've been \n"
           "coming for years whereas you started working here since last "
           "month.\n"
        << std::endl;
}

void Harl::error(void) {
    std::cout << "[" YELLOW " ERROR " RES "]"
              << "\nThis is unacceptable! I want to speak to the manager now."
              << std::endl;
}
