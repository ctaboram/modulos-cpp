#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <stdexcept>
# include <string>

class Bureaucrat;
class Form
{
	private:
		const std::string _name ;
		bool	_signed;
		int		_gradeF;
		int		_gradeE;
	public:
		Form();
		Form(std::string name, int gradeF, int gradeE);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeF() const;
		int			getGradeE() const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		void beSigned(const Bureaucrat &bureaucrat);

};
std::ostream	&operator<<(std::ostream &o, const Form &a);

#endif