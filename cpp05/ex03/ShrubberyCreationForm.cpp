#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm",145,137), _target("default")
{
    std::cout << "ShrubberyCreationForm constructor default called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm",145,137),_target(target)
{
    std::cout << "ShrubberyCreationForm constructor with parameter called"<< std::endl;   
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
    if(this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;	
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if(!getSigned())
        throw AForm::NotSignedException();
    if(executor.getGrade() > getGradeE())
        throw AForm::GradeTooLowException();
    std::string filename = this->_target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if(!outfile.is_open())
    {
        std::cout << "ERROR" << std::endl;
        return ;
    }
    outfile << TREE;
    outfile.close();
}