#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm",72,45), _target("default")
{
    std::cout << "RobotomyRequestForm constructor default called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm",72,45),_target(target)
{
    std::cout << "RobotomyRequestForm constructor with parameter called"<< std::endl;   
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    if(this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;	
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if(!getSigned())
        throw AForm::NotSignedException();
    if(executor.getGrade() > getGradeE())
        throw AForm::GradeTooLowException();
    std::cout << "* VRRRRRRR... BZZZZZZ... *" << std::endl;
    if(std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized succesfully!" << std::endl;
    else
        std::cout << "The robotomy failed on " << _target << "." << std::endl;
}