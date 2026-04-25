#include "dog.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(std::string type): Animal(type){
    std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog &src): Animal(src)
{
    std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Dog assignation operator called" << std::endl;
	this->_type = rhs._type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "guau!" << std::endl;
}