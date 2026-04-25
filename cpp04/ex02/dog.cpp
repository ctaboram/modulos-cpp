#include "dog.hpp"

Dog::Dog(): AAnimal("Dog")
{
    this->_brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type): AAnimal(type)
{
    this->_brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src): AAnimal(src)
{
    std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
	*this = src;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
		*this->_brain = *rhs._brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "guau!" << std::endl;
}

void Dog::setIdea(int index, std::string idea)
{
    this->_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    return this->_brain->getIdea(index);
}