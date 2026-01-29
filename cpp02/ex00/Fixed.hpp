#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
    private:
        int     _value;
        static const  int _fractionalBits;
    public:
        Fixed(); //constructor
        Fixed(const Fixed &cpy); // constructor copia, crear un objeto nuevo
        Fixed& operator=(const Fixed &copy); // Operacion de asiganacion interambiar un objeto ya existente
        ~Fixed(); //destructor

        int getRawBits(void) const;
        void    setRawBits(const int raw);

};

#endif