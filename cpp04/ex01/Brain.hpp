#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    
    public:
        Brain();                                // Default constructor
        Brain(const Brain &src);                // Copy constructor
        ~Brain();                               // Destructor
        Brain &operator=(const Brain &rhs);     // Assignment operator
        
        // Métodos para acceder/modificar ideas (opcional pero útil)
        std::string getIdea(int index) const;
        void setIdea(int index, std::string idea);
};

#endif