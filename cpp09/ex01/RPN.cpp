#include "RPN.hpp"

Rpn::Rpn(){}

Rpn::~Rpn(){}

Rpn::Rpn(const Rpn &other)
{
    this->_stack = other._stack;
}
Rpn &Rpn::operator=(const Rpn &other)
{
    if(this != &other)
        _stack = other._stack;
    return *this;
}
void Rpn::calculate(const std::string &expression)
{
    for(size_t i = 0; i < expression.length();i++)
    {
        char c = expression[i];
        if(c == ' ')
            continue;
        else if(isdigit(c))
            this->_stack.push(c - '0');
        else if( c == '+' || c == '-' || c == '*' || c == '/')
        {
            if(_stack.size() < 2)
            {
                std::cout << "Error" << std::endl;
                return;
            }
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            int result = 0;
            if(c == '+')
                result = a + b;
            else if(c == '*')
                result = a * b;
            else if(c == '-')
                result = a - b;
            else if(c == '/')
            {
                if(b == 0)
                {
                    std::cout << "Error" << std::endl;
                    return;
                }
                result = a / b;
            }
            this->_stack.push(result);
            
        }
    }
    if(_stack.size() == 1)
    {
        std::cout << _stack.top() << std::endl;
    }
    else
    {
        std::cout<< "Error"<< std::endl;
        return;
    }
}