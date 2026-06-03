#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void identify(Base* t)
{
    if (dynamic_cast<A*>(t))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(t))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(t))
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(...){}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(...){}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(...){}
}