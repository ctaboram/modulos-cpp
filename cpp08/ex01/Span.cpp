#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int size)
{
    _size = size;
}

Span::~Span()
{
}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    _size = other._size;
    _numbers = other._numbers;
    return *this;
}

const char *Span::Fullexception::what() const throw() {
    return "Full exception";
}

const char *Span::NotEnoughException::what() const throw() {
    return "Not enough exception";
}

void Span::addNumber(int num)
{
    if (_numbers.size() >= _size)
        throw Fullexception();
    _numbers.push_back(num);
}

unsigned int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw NotEnoughException();

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int min_span = static_cast<unsigned int>(static_cast<long long>(sorted[1]) - static_cast<long long>(sorted[0]));
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        unsigned int span = static_cast<unsigned int>(static_cast<long long>(sorted[i + 1]) - static_cast<long long>(sorted[i]));
        if (span < min_span)
            min_span = span;
    }
    return min_span;
}

unsigned int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw NotEnoughException();

    int min_val = *std::min_element(_numbers.begin(), _numbers.end());
    int max_val = *std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(static_cast<long long>(max_val) - static_cast<long long>(min_val));
}


