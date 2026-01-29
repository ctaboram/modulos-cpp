#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
    std::cout << "Fixed object created with constructor" << std::endl;
}
Fixed::~Fixed()
{
    std::cout << "Fixed object destroyed" << std::endl;
}
Fixed::Fixed(const Fixed &cpy)
{
    std::cout << "Fixed object copied" << std::endl;
    *this = cpy; 
}
Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Assigment operator called"<< std::endl;
    this->_value = copy.getRawBits();
    return(*this);
}

int Fixed::getRawBits() const
{
    std::cout << "getrawBits member function called" << std::endl;
    return(this->_value);
}
void    Fixed::setRawBits(const int raw)
{
    this->_value = raw;
}
int Fixed::toInt() const
{
    return(this->_value >> _fractionalBits);
}
float Fixed::toFloat() const
{
    return static_cast<float>(_value) / (1 << _fractionalBits);
}