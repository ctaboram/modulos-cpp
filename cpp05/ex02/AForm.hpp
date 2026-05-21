#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <stdexcept>
# include <string>

class Bureaucrat;
class AForm
{
	private:
		const std::string _name ;
		bool	_signed;
		int		_gradeF;
		int		_gradeE;
	public:
		AForm();
		AForm(std::string name, int gradeF, int gradeE);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		virtual ~AForm();

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
		class NotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

};
std::ostream	&operator<<(std::ostream &o, const AForm &a);

#endif