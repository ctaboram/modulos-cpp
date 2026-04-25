#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
class Dog: public Animal {
    public:
        Dog();							// Default constructor
		Dog(const Dog &src);			// Copy constructor
		virtual ~Dog();					// Destructor
		Dog &operator=(const Dog &rhs);	// Assignment operator

        Dog(std::string type);
        virtual void makeSound() const;
};
#endif