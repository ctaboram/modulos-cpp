#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
class Cat: public Animal {
    public:
        Cat();							// Default constructor
		Cat(const Cat &src);			// Copy constructor
		virtual ~Cat();					// Destructor
		Cat &operator=(const Cat &rhs);	// Assignment operator

        Cat(std::string type);
        virtual void makeSound() const;
};
#endif