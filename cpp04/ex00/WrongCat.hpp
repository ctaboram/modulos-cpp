#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();									// Default constructor
	WrongCat(const WrongCat &src);				// Copy constructor
	~WrongCat();								// Destructor
	WrongCat &operator=(const WrongCat &rhs);	// Assignment operator

	WrongCat(std::string type);

	void makeSound() const;
};

#endif