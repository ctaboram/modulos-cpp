#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other) {
    *this = other;
}

Intern& Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}
AForm* Intern::makeForm(const std::string formName, const std::string target)
{
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    int i = 0;
    int formIndex = -1;
    while(i < 3)
    {
        if(formName == formNames[i])
        {
            formIndex = i;
            break;
        }
        i++;
    }

    switch (formIndex)
    {
    case 0:
        std::cout << "Intern creates " << formName << std::endl;
        return new ShrubberyCreationForm(target);
    case 1:
        std::cout << "Intern creates " << formName << std::endl;
        return new RobotomyRequestForm(target);
    case 2:
        std::cout << "Intern creates " << formName << std::endl;
        return new PresidentialPardonForm(target);
    
    default:
        std::cout << "Intern couldn't create form: " << formName << " doesn't exist" << std::endl;
        return NULL;
    }
}
