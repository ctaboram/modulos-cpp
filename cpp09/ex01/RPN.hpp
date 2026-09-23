#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <ctype.h>

class Rpn
{
private:
    std::stack<int> _stack;
public:
    Rpn();
    ~Rpn();
    Rpn(const Rpn &other);
    Rpn &operator=(const Rpn &other);

    void calculate(const std::string &expression);
};
#endif