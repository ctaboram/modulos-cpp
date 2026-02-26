#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>

class Animal {
    protected:
        std::string _type;
    public:
        Animal();								// Default constructor
		Animal(const Animal &src);				// Copy constructor
		virtual ~Animal();						// Destructor
		Animal &operator=(const Animal &rhs);	// Assignment operator

        Animal(std::string type);

        virtual std::string getType() const;
        virtual void makeSound() const;

};
#endif