#include <iostream>

#include "AAnimal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main()
{
    std::cout << "=== Polymorphism with abstract AAnimal ===" << std::endl;
    const int size = 4;
    AAnimal *zoo[size];

    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            zoo[i] = new Dog();
        else
            zoo[i] = new Cat();
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << zoo[i]->getType() << " -> ";
        zoo[i]->makeSound();
    }

    for (int i = 0; i < size; i++)
        delete zoo[i];

    std::cout << "\n=== test (Dog) ===" << std::endl;
    Dog basic;
    basic.setIdea(0, "Quiero un hueso");

    Dog copy = basic;
    basic.setIdea(0, "Ahora quiero dormir");

    std::cout << "basic idea[0]: " << basic.getIdea(0) << std::endl;
    std::cout << "copy  idea[0]: " << copy.getIdea(0) << std::endl;

    std::cout << "\n=== test (Cat) ===" << std::endl;
    Cat cat1;
    cat1.setIdea(0, "Cazar ratones");

    Cat cat2(cat1);
    cat1.setIdea(0, "Dormir en el sofa");

    std::cout << "cat1 idea[0]: " << cat1.getIdea(0) << std::endl;
    std::cout << "cat2 idea[0]: " << cat2.getIdea(0) << std::endl;

    return 0;
}
