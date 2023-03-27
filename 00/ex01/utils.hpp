#ifndef UTILS_HPP
#define UTILS_HPP

#define RED "\x1b[38;5;88m"
#define BLUE "\x1b[38;5;25m"
#define GREEN "\x1b[38;5;40m"
#define YELLOW "\x1b[38;5;220m"
#define RES "\x1b[0m"

#define _ACEPT GREEN "[+] " RES
#define _ERROR RED "[-] " RES

#include <iostream>

std::string initName(std::string str);
std::string initMessage(std::string str);
std::string initPhoneNumber(std::string str);
std::string truncateStr(std::string str);

#endif
