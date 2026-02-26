#include "dog.hpp"

dog::dog(): Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
}
dog::dog(std::string type): Animal(type){
    std::cout << "Dog default cosntructor called" << std::endl;
}
dog::dog(const dog &src): Animal(src)
{
    std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}
dog::~dog() {
	std::cout << "dog destructor called" << std::endl;
}

dog &dog::operator=(const dog &rhs) {
	std::cout << "dog assignation operator called" << std::endl;
	this->_type = rhs._type;
	return *this;
}

void dog::makeSound() const {
	std::cout << "guau!" << std::endl;
}