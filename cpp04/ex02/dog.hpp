#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal {
    private:
        Brain *_brain;

    public:
        Dog();							// Default constructor
		Dog(const Dog &src);			// Copy constructor
		virtual ~Dog();					// Destructor
		Dog &operator=(const Dog &rhs);	// Assignment operator

        Dog(std::string type);
        virtual void makeSound() const;

        void setIdea(int index, std::string idea);
        std::string getIdea(int index) const;
};
#endif