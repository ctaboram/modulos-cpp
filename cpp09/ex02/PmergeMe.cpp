#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};
PmergeMe::~PmergeMe() {};
PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->_vector = other._vector;
	this->_deque = other._deque;
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if(this != &other)
	{
        _vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

void PmergeMe::process(int ac, char **av)
{
	if(ac < 2)
	{
		std::cout << "Error" << std::endl;
		return;
	}
	for(int i = 1; i < ac;i++)
	{
		std::string str = av[i];

		for(int j = 0; j < str.length();j++)
		{
			if(!isdigit(str[j]))
			{
				std::cout << "Error" << std::endl;
				return;
			}
		}
		long num = atol(av[i]);
		if(num > 2147483647)
		{
			std::cout << "Error" << std::endl;
			return;
		}
		this->_vector.push_back(static_cast<int>(num));
		this->_deque.push_back(static_cast<int>(num));

	}
	std::cout<< "Before: ";
	for(size_t i = 0; i < _vector.size(); i++)
	{
		std::cout << this->_vector[i] << " ";
	}
	std::cout << std::endl;

	if(ac == 2)
		return;


}
