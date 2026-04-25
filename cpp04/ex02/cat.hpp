#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal {
    private:
        Brain *_brain;

    public:
        Cat();							// Default constructor
		Cat(const Cat &src);			// Copy constructor
		virtual ~Cat();					// Destructor
		Cat &operator=(const Cat &rhs);	// Assignment operator

        Cat(std::string type);
        virtual void makeSound() const;

        void setIdea(int index, std::string idea);
        std::string getIdea(int index) const;
};
#endif