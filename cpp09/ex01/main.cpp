#include "RPN.hpp"

int main(int ac,char **av)
{
    if(ac != 2)
    {
        std::cout << "ERROR" << std::endl;
        return 0;
    }
    Rpn calculator;
    calculator.calculate(av[1]);
    return 0;
}