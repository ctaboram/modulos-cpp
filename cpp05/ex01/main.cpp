#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		std::cout << "=== Test 1: Create a Bureaucrat and a Form ===" << std::endl;
		Bureaucrat b1("Alice", 5);
		Form f1("Manolo", 10, 20);
		
		std::cout << b1 << std::endl;
		std::cout << f1 << std::endl;

		std::cout << "\n=== Test 2: Sign the Form with sufficient grade ===" << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n=== Test 3: Try to sign with insufficient grade ===" << std::endl;
		Bureaucrat b2("Bob", 50);
		Form f2("Top Secret Form", 10, 20);
		
		std::cout << b2 << std::endl;
		std::cout << f2 << std::endl;
		b2.signForm(f2);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== All tests completed ===" << std::endl;
	return 0;
}