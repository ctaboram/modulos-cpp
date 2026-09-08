#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "Range of iterators" << std::endl;
    Span sp2 = Span(5);
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    //vec.push_back(60);
    try
    {
        sp2.addNumber(vec.begin(), vec.end());
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (const Span::Fullexception &exception)
    {
        std::cout << exception.what() << std::endl;
    }
    return 0;
}
