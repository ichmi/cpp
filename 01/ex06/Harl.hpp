#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <map>

#define RED "\x1b[38;5;88m"
#define BLUE "\x1b[38;5;25m"
#define YELLOW "\x1b[38;5;220m"
#define RES "\x1b[0m"
#define _ERROR RED "- " RES

enum { DEBUG, INFO, WARNING, ERROR };

class Harl {
   private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

   public:
    Harl(void);
    ~Harl(void);

    void complain(std::string level);
};

#endif
