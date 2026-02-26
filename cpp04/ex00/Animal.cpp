#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal constructor called" << std::endl;
}
Animal::Animal(const Animal &src)
{
    std::cout << "Animal copy contructor called" << std::endl;
    *this = src;
}
Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}
Animal &Animal::operator=(const Animal &rhs)
{
    std::cout << "Animal assignation operator called"<< std::endl;
    this->_type = rhs._type;
    return *this;
}
std::string Animal::getType() const 
{
    return this->_type;
}

void Animal::makeSound() const {
    std::cout << "Animal can't make sound" << std::endl;
}