#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
# include <cmath>

class Fixed {
    private:
        int     _value;
        static const  int _fractionalBits;
    public:
        Fixed(); //constructor
        Fixed(const int value);
		Fixed(const float value);
        Fixed(const Fixed &cpy); // constructor copia, crear un objeto nuevo
        Fixed& operator=(const Fixed &copy); // Operacion de asiganacion interambiar un objeto ya existente
        ~Fixed(); //destructor

        int     getRawBits(void) const;
        void    setRawBits(const int raw);
        int     toInt() const;
        float   toFloat() const;
        //operaciones de comparacion
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        //operaciones aritmeticas
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

};
std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);
#endif