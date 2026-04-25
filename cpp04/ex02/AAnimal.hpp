#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
    protected:
        std::string _type;

    public:
        AAnimal();                                 // Default constructor
        AAnimal(const AAnimal &src);               // Copy constructor
        virtual ~AAnimal();                        // Destructor
        AAnimal &operator=(const AAnimal &rhs);    // Assignment operator

        AAnimal(std::string type);

        std::string getType() const;
        virtual void makeSound() const = 0;
};

#endif
