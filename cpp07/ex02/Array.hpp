#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
    private:
        T               *_arr;
        unsigned int    _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        ~Array();

        Array& operator=(const Array& other);

        T& operator[](unsigned int index) const;

        unsigned int size() const;

        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw();
    };
};
#include "Array.tpp" 
#endif