#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#define BLUE "\x1b[38;5;25m"
#define CYAN "\x1b[38;5;51m"
#define YELLOW1 "\x1b[38;5;220m"
#define YELLOW2 "\x1b[38;5;222m"
#define PURPLE1 "\x1b[38;5;162m"
#define PURPLE2 "\x1b[38;5;90m"
#define PURPLE3 "\x1b[38;5;126m"
#define RED "\x1b[38;5;196m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>
#include <cctype>
#include <sstream>
#include <climits>
#include <limits>
#include <cstdlib>
#include <iomanip>

class ScalarConverter {
    private:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const &obj);
        ~ScalarConverter(void);
        ScalarConverter &operator=(ScalarConverter const &rhs);

        static char   _char;
        static int    _int;
        static float  _float;
        static double _double;

        static void putChar(std::string::iterator const &it);
        
        static void _echoChar(long double const value);
        static void _echoInt(long double const value);
        static void _echoFloat(long double const value);
        static void _echoDouble(long double const value);

    public:
        static void convert(std::string const &s);
};

#endif

