#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), _signed(false), _gradeF(10), _gradeE(10)
{
	if (_gradeF < 1 || _gradeE < 1)
		throw AForm::GradeTooHighException();
	if (_gradeF > 150 || _gradeE > 150)
		throw AForm::GradeTooLowException();
	std::cout << " AForm default constructor called" << std::endl;
}
AForm::AForm(std::string name, int gradeF, int gradeE): _name(name), _signed(false), _gradeF(gradeF), _gradeE(gradeE)
{
	if (_gradeF < 1 || _gradeE < 1)
		throw AForm::GradeTooHighException();
	if (_gradeF > 150 || _gradeE > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm " << this->_name << " created with grade required to sign it " << this->_gradeF << " and grade required to execute it " << this->_gradeE << std::endl;
}
AForm::AForm(const AForm &other): _name(other.getName()),_signed(other.getSigned()), _gradeF(other.getGradeF()), _gradeE(other.getGradeE())
{
	std::cout << "AForm constructor copy called" << std::endl;
}
AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm Assignation operator called" << std::endl;
	if(this != &other)
	{
		this->_signed = other.getSigned();
		this->_gradeF = other.getGradeF();
		this->_gradeE = other.getGradeE();
	}
	return *this;
}
AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;	
}

std::string AForm::getName() const
{
	return _name;
}
bool AForm::getSigned() const
{
	return _signed;
}
int AForm::getGradeF() const
{
	return _gradeF;
}
int AForm::getGradeE() const
{
	return _gradeE;
}
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
const char *AForm::NotSignedException::what() const throw()
{
	return "Not signed form";
}
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeF)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}
std::ostream &operator<<(std::ostream &o, const AForm &a)
{
	o << "Name: "<< a.getName() << std::endl <<"Signed: " << (a.getSigned() ? "yes" : "no") << std::endl
	  << "Grade to sign: " << a.getGradeF()  << std::endl
	  << "Grade to execute: " << a.getGradeE() << std::endl;
	return o;
}