#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm",25,5), _target("default")
{
    std::cout << "PresidentialPardonForm constructor default called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm",25,5),_target(target)
{
    std::cout << "PresidentialPardonForm constructor with parameter called"<< std::endl;   
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target)
{
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
    if(this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;	
}
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if(!getSigned())
        throw AForm::NotSignedException();
    if(executor.getGrade() > getGradeE())
        throw AForm::GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}