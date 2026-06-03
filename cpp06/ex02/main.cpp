#include <iostream>
#include "Base.hpp"
#include "Generate.hpp"
#include "Identify.hpp"

int main()
{
	for (int i = 0; i < 3; ++i)
	{
		Base* ptr = generate();
		std::cout << "Run " << (i + 1) << ":" << std::endl;
		identify(ptr);
		identify(*ptr);
		delete ptr;
		std::cout << std::endl;
	}

	return 0;
}