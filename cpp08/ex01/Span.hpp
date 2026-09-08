#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>


class Span {
    private:
        unsigned int _size;
        std::vector<int> _numbers;

    public:
        class Fullexception : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class NotEnoughException : public std::exception
        {
            public:
                const char *what() const throw();
        };
        Span(unsigned int size);
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span &other);
        
        void addNumber(int num);
        
        unsigned int shortestSpan();
        unsigned int longestSpan();

        template <typename T>
        void addNumber(T first, T last);
};

template <typename T>
void Span::addNumber(T first, T last)
{
    for (T it = first; it != last; ++it)
	{
		if (_numbers.size() >= _size)
			throw Fullexception();
		_numbers.push_back(*it);
	}
}

#endif