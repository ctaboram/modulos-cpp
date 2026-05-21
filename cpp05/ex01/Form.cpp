#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("default"), _signed(false), _gradeF(10), _gradeE(10)
{
	if (_gradeF < 1 || _gradeE < 1)
		throw Form::GradeTooHighException();
	if (_gradeF > 150 || _gradeE > 150)
		throw Form::GradeTooLowException();
	std::cout << " Form default constructor called" << std::endl;
}
Form::Form(std::string name, int gradeF, int gradeE): _name(name), _signed(false), _gradeF(gradeF), _gradeE(gradeE)
{
	if (_gradeF < 1 || _gradeE < 1)
		throw Form::GradeTooHighException();
	if (_gradeF > 150 || _gradeE > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form " << this->_name << " created with grade required to sign it " << this->_gradeF << " and grade required to execute it " << this->_gradeE << std::endl;
}
Form::Form(const Form &other): _name(other.getName()),_signed(other.getSigned()), _gradeF(other.getGradeF()), _gradeE(other.getGradeE())
{
	std::cout << "Form constructor copy called" << std::endl;
}
Form &Form::operator=(const Form &other)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if(this != &other)
	{
		this->_signed = other.getSigned();
		this->_gradeF = other.getGradeF();
		this->_gradeE = other.getGradeE();
	}
	return *this;
}
Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;	
}

std::string Form::getName() const
{
	return _name;
}
bool Form::getSigned() const
{
	return _signed;
}
int Form::getGradeF() const
{
	return _gradeF;
}
int Form::getGradeE() const
{
	return _gradeE;
}
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeF)
		throw Form::GradeTooLowException();
	this->_signed = true;
}
std::ostream &operator<<(std::ostream &o, const Form &a)
{
	o << "Name: "<< a.getName() << std::endl <<"Signed: " << (a.getSigned() ? "yes" : "no") << std::endl
	  << "Grade to sign: " << a.getGradeF()  << std::endl
	  << "Grade to execute: " << a.getGradeE() << std::endl;
	return o;
}