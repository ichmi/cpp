#ifndef RPN_HPP
#define RPN_HPP

#define RED "\x1b[38;5;196m"
#define BLUE "\x1b[38;5;25m"
#define CYAN "\x1b[38;5;51m"
#define GRAY "\x1b[38;5;8m"
#define GREEN "\x1b[38;5;40m"
#define RES "\x1b[0m"

#include <iostream>
#include <stack>
#include <sstream>

class RPN {
    private:
        RPN(void);

        static std::stack<int> operands;

        static bool isOperator(std::string const &token);
        static int  operate(std::string const &token);

    public:
        RPN(RPN const &obj);
        ~RPN(void);
        RPN &operator=(RPN const &rhs);

        static int eval(std::string const &expression);
};

#endif
