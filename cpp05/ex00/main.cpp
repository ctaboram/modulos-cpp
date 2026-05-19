#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "=== Test 1: Create Bureaucrat ===" << std::endl;
		Bureaucrat b1("Alice", 50);
		std::cout << b1 << std::endl;

		std::cout << "\n=== Test 2: Increment grade ===" << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;

		std::cout << "\n=== Test 3: Decrement grade ===" << std::endl;
		b1.decrementGrade();
		b1.decrementGrade();
		std::cout << b1 << std::endl;

		std::cout << "\n=== Test 4: Try grade too high ===" << std::endl;
		Bureaucrat b2("Bob", 1);
		b2.incrementGrade();


	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Test 5: Try grade too low ===" << std::endl;
		Bureaucrat b3("Charlie", 150);
		b3.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Tests completed ===" << std::endl;
	return 0;
}