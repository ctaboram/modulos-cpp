#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
    std::srand(time(NULL));

    try {
        Bureaucrat jefe("El Jefe", 1);
        
        ShrubberyCreationForm form1("Jardin");
        RobotomyRequestForm form2("Bender");
        PresidentialPardonForm form3("Arthur");

        std::cout << "\n--- TEST SHRUBBERY ---" << std::endl;
        jefe.signForm(form1);
        jefe.executeForm(form1);

        std::cout << "\n--- TEST ROBOTOMY ---" << std::endl;
        jefe.signForm(form2);
        jefe.executeForm(form2);
        
        std::cout << "\n--- TEST PRESIDENTIAL ---" << std::endl;
        jefe.signForm(form3);
        jefe.executeForm(form3);

    } 
    catch (std::exception &e) {
        std::cout << "Algo fallo: " << e.what() << std::endl;
    }

    return 0;
}