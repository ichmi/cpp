#include "ScalarConverter.hpp"

char   ScalarConverter::_char   = '\0';
int    ScalarConverter::_int    = 0;
float  ScalarConverter::_float  = 0.f;
double ScalarConverter::_double = 0.;

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &obj) {
    (void) obj;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
    (void) rhs;

    return *this;
}

void ScalarConverter::convert(std::string const &literal) {
    if (literal.empty()) {
        std::cerr << RED "Invalid literal" RED << std::endl;
        return ;
    }

    std::cout << std::setprecision(5);
    
    std::string s = literal;

    if (s == "+inf" || s == "-inf" || s == "nan") {
        std::cout << "char:    " RED "impossible" RES << std::endl;
        std::cout << "int:     " RED "impossible" RES << std::endl;
        std::cout << "float:   " YELLOW1 << s << "f" RES << std::endl;
        std::cout << "double:  " YELLOW1 << s << RES << std::endl;
        return ;
    }

    if (s == "+inff" || s == "-inff" || s == "nanf") {
        std::cout << "char:    " RED "impossible" RES << std::endl;
        std::cout << "int:     " RED "impossible" RES << std::endl;
        std::cout << "float:   " YELLOW1 << s << RES << std::endl;
        std::cout << "double:  " YELLOW1 << s << RES << std::endl;
        return ;
    }

    if (s.size() == 1 && !std::isdigit(*(s.begin()))) {
        ScalarConverter::putChar(s.begin());
        return ;
    }

    int dotCount = 0;
    for (std::string::iterator it = s.begin(); it != s.end(); ++it) {
        if ((*it == '-' || *it == '+') && it == s.begin()) {
            continue ;
        }
        if (!std::isdigit(*it)) {
            if (*it == '.') {
                dotCount++;
            } else if (*it == 'f' && (it + 1) == s.end()) {
                if (!dotCount) {
                    std::cerr << RED "invalid literal" RES << std::endl;
                    return ;
                }
                break ;
            } else {
                std::cerr << RED "invalid literal" RES << std::endl;
                return ;
            }
        }
    }

    if (dotCount > 1) {
        std::cerr << RED "invalid literal" RES << std::endl;
        return ;
    }

    long double const value = std::strtold(s.c_str(), NULL);

    ScalarConverter::_echoChar(value);
    ScalarConverter::_echoInt(value);
    ScalarConverter::_echoFloat(value);
    ScalarConverter::_echoDouble(value);
}

void ScalarConverter::putChar(std::string::iterator const &it) {
    if (std::isspace(*it)) {
        char const  nonPrintable[7] = " \n\t\r\f\v";
        char const *output[6] = {"' '", "\\n", "\\t", "\\r", "\\f", "\\v"};

        for (int i = 0; i < 7; ++i) {
            if (*it == nonPrintable[i]) {
                std::cout << "char:    " << YELLOW1 << output[i] << RES << std::endl;
            }
        }
    }
    else if (!std::isprint(*it)) {
        std::cout << "char:   " GRAY "non-displayable" RES << std::endl;
    } else {
        std::cout << "char:    " YELLOW1 << *it << RES << std::endl;
    }
    std::cout << "int:     " YELLOW1 << std::fixed << static_cast<int>(*it) << RES << std::endl;
    std::cout << "float:   " YELLOW1 << std::fixed << static_cast<float>(*it) << RES << std::endl;
    std::cout << "double:  " YELLOW1 << std::fixed << static_cast<double>(*it) << RES << std::endl;
}

void ScalarConverter::_echoChar(long double const value) {
    char const ch = static_cast<char>(value);

    if (value < CHAR_MIN || value > CHAR_MAX) {
        std::cout << "char:    " RED "impossible" RES << std::endl;
    } else if (std::isspace(ch)) {
        char const  nonPrintable[7] = " \n\t\r\f\v";
        char const *output[6] = {" ' '", "\\n", "\\t", "\\r", "\\f", "\\v",};

        for (int i = 0; i < 7; ++i) {
            if (ch == nonPrintable[i]) {
                std::cout << "char:   " << YELLOW1 << output[i] << RES << std::endl;
                return ;
            }
        }
    } else if (!std::isprint(ch)) {
        std::cout << "char:    " GRAY "non-displayable" RES << std::endl;
    } else {
        std::cout << "char:    " YELLOW1 << ch << RES << std::endl;
    }
}

void ScalarConverter::_echoInt(long double const value) {
    int const intValue = static_cast<int>(value);

    if (value < INT_MIN || value > INT_MAX) {
        std::cout << "int:     " RED "impossible" RES << std::endl;
    } else {
        std::cout << "int:     " YELLOW1 << intValue << RES << std::endl;
    }
}

void ScalarConverter::_echoFloat(long double const value) {
    float const floatValue = static_cast<float>(value);

    float const minFloat = -std::numeric_limits<float>::max();
    float const maxFloat = std::numeric_limits<float>::max();

    if (value < minFloat || value > maxFloat) {
        std::cout << "float:   " RED "impossible" RES << std::endl;
    } else {
        std::cout << "float:   " YELLOW1 << floatValue << "f" RES << std::endl;
    }
}

void ScalarConverter::_echoDouble(long double const value) {
    double const doubleValue = static_cast<double>(value);

    double const minDouble = -std::numeric_limits<double>::max();
    double const maxDouble = std::numeric_limits<double>::max();

    if (value < minDouble || value > maxDouble) {
        std::cout << "double:  " RED "impossible" RES << std::endl;
    } else {
        std::cout << "double:  " YELLOW1 << doubleValue << RES << std::endl;
    }
}
