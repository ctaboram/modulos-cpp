#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat ::Bureaucrat(): _name("default"), _grade(150)
{
	std::cout << " Bureaucrat default Constructor called" << std::endl;
}
Bureaucrat ::Bureaucrat(const std::string &name,int grade): _name(name), _grade(grade)
{

	if(grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	if(grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	 std::cout << "Bureaucrat " << this->_name << " created with grade " << this->_grade << std::endl;
}
Bureaucrat:: Bureaucrat(const Bureaucrat &other): _name(other.getName()), _grade(other.getGrade())
{
	std::cout << "Bureaucrat constructor copy called" << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if(this != &other)
		this->_grade = other.getGrade();
	return *this;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor for " << this->getName() << " called" << std::endl;
}
std::string Bureaucrat::getName() const
{
	return _name;
}
int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	if(_grade - 1 < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}
void Bureaucrat::decrementGrade()
{
	if(_grade + 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!!!";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!!";
}

void Bureaucrat::signForm(AForm &Aform)
{
	try
	{
		Aform.beSigned(*this);
		std::cout << this->_name << " signed " << Aform.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't sign " << Aform.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}

}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &a)
{
	o << a.getName() << ", bureaucrat grade " << a.getGrade();
	return o;
}
