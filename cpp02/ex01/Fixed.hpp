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

};
std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);
#endif