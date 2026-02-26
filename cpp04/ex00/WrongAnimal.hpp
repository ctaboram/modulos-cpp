#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>
class WrongAnimal {
    protected:
        std::string _type;
    public:
		WrongAnimal();									// Default constructor
		WrongAnimal(const WrongAnimal &src);			// Copy constructor
		~WrongAnimal();									// Destructor
		WrongAnimal &operator=(const WrongAnimal &rhs);	// Assignment operator

		WrongAnimal(std::string type);

		std::string getType() const;
		void makeSound() const;
};
#endif