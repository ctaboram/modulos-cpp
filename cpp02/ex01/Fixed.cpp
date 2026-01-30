#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}
Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->_value = value << _fractionalBits;
}
Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->_value = static_cast<int>(roundf(value * (1 << _fractionalBits)));
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

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
    str << fixed_nbr.toFloat();
    return str;
}