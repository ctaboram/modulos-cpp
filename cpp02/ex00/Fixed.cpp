#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const Fixed &cpy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_value = cpy.getRawBits(); 
}
Fixed &Fixed::operator=(const Fixed &copy)
{
    std::cout << "Copy assignment operator called"<< std::endl;
    this->_value = copy.getRawBits();
    return(*this);
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_value);
}
void    Fixed::setRawBits(const int raw)
{
    this->_value = raw;
}