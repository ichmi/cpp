#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(RPN const &obj) {
    *this = obj;
}

RPN::~RPN(void) {}

RPN &RPN::operator=(RPN const &rhs) {
    (void) rhs;
    return *this;
}

std::stack<int> RPN::operands;

int RPN::eval(std::string const &expression) {
    std::istringstream iss(expression);
    std::string token;
    bool isOperatorAvaiable = false;

    while (iss >> token) {
        if (iss.fail()) {
            throw std::runtime_error("Error: Could not parse argument expression");
        }

        if (token.size() > 1) {
            throw std::invalid_argument("Error: Invalid token");
        }

        if (std::isdigit(token[0])) {
            std::istringstream issT(token);
            int value;

            issT >> value;
            if (issT.fail()) {
                throw std::runtime_error("Error: Could not redirect token");
            }
            RPN::operands.push(value);
        } else if (RPN::isOperator(token)) {
            if (RPN::operands.size() < 2) {
                throw std::invalid_argument("Error: Missing operands to evaluate");
            }

            isOperatorAvaiable = true;

            int const result = RPN::operate(token);
            RPN::operands.push(result);
        } else {
            throw std::invalid_argument("Error: Invalid argument");
        }
    }

    if (!isOperatorAvaiable) {
        throw std::invalid_argument("Error: Missing operator");
    }


    int const result = RPN::operands.top();
    RPN::operands.pop();

    if (RPN::operands.empty()) {
        return result;
    }

    throw std::invalid_argument("Error: Stack not empty (missing operator)");
}

bool RPN::isOperator(std::string const &token) {
    std::istringstream iss(token);
    char ch;

    iss >> ch;
    if (iss.fail()) {
        throw std::runtime_error("Error: Could not redirect char token");
    }

    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return true;
    }
    return false;
}

int RPN::operate(std::string const &token) {
    std::istringstream iss(token);
    char ch;

    int const y = RPN::operands.top();
    RPN::operands.pop();
    int const x = RPN::operands.top();
    RPN::operands.pop();

    iss >> ch;
    if (iss.fail()) {
        throw std::runtime_error("Error: Could not redirect char token");
    }

    switch (ch) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            if (y == 0) {
                throw std::runtime_error("Error: Zero division");
            }
            return x / y;
    }

    throw std::runtime_error("Error: Invalid operator");
}
