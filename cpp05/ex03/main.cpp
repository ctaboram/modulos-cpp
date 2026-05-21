#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>


int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Manolo", 1);
    
    AForm* form;

    std::cout << "\n--- TEST 1: Create a valid Robotomy form ---" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << "\n--- TEST 2: Try to create a non-existent form ---" << std::endl;
    form = someRandomIntern.makeForm("non existent form", "Random Target");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    return 0;
}