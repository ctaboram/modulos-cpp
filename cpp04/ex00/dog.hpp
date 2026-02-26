#ifndef dog_HPP
#define dog_HPP

#include "Animal.hpp"
class dog: public Animal {
    public:
        dog();							// Default constructor
		dog(const dog &src);			// Copy constructor
		virtual ~dog();					// Destructor
		dog &operator=(const dog &rhs);	// Assignment operator

        dog(std::string type);
        virtual void makeSound() const;
};
#endif