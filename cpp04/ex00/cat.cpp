#include "cat.hpp"

cat::cat(): Animal("Cat"){
    std::cout << "Cat default constructor called" << std::endl;
}
cat::cat(std::string type): Animal(type){
    std::cout << "Cat default constructor called" << std::endl;
}
cat::cat(const cat &src): Animal(src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}
cat::~cat() {
	std::cout << "Cat destructor called" << std::endl;
}
cat &cat::operator=(const cat &rhs) {
	std::cout << "cat assignation operator called" << std::endl;
	this->_type = rhs._type;
	return *this;
}

void cat::makeSound() const {
	std::cout << "Miaouuu!" << std::endl;
}