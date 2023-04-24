#ifndef UTILS_HPP
#define UTILS_HPP

#define BLUE "\x1b[38;5;25m"
#define CYAN "\x1b[38;5;51m"
#define YELLOW "\x1b[38;5;220m"
#define PURPLE "\x1b[38;5;162m"
#define RED "\x1b[38;5;196m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#define _ACC GREEN "+ " GRAY
#define _WAR YELLOW "! " GRAY
#define _ERR RED "- " GRAY

#include <iostream>

std::string initName(std::string str);
std::string initMessage(std::string str);
std::string initPhoneNumber(std::string str);
std::string truncateStr(std::string str);

#endif
