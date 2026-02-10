/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:13:56 by ctaboada          #+#    #+#             */
/*   Updated: 2026/02/03 13:13:57 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

bool    Fixed::operator>( const Fixed &other) const
{
    return _value > other._value;   
}
bool    Fixed::operator<( const Fixed &other) const
{
    return _value < other._value;   
}
bool    Fixed::operator>=( const Fixed &other) const
{
    return _value >= other._value;   
}
bool    Fixed::operator<=( const Fixed &other) const
{
    return _value <= other._value;   
}
bool    Fixed::operator==( const Fixed &other) const
{
    return _value == other._value;   
}
bool    Fixed::operator!=( const Fixed &other) const
{
    return _value != other._value;   
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(_value + other._value);
    return result;
}
Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(_value - other._value);
    return result;
}
Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((_value * other._value) >> _fractionalBits);
    return result;
}
Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((_value << _fractionalBits) / other._value    );
    return result;
}

Fixed& Fixed::operator++()
{
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    _value++;
    return tmp;
}

Fixed& Fixed::operator--()
{
    --_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    _value--;
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
    str << fixed_nbr.toFloat();
    return str;
}
