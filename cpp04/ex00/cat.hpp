#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
class cat: public Animal {
    public:
        cat();							// Default constructor
		cat(const cat &src);			// Copy constructor
		virtual ~cat();					// Destructor
		cat &operator=(const cat &rhs);	// Assignment operator

        cat(std::string type);
        virtual void makeSound() const;
};
#endif