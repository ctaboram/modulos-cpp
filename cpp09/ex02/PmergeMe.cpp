#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->_vector = other._vector;
    this->_deque = other._deque;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

void PmergeMe::sortVector(std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return;
    int saved = -1;
    bool snitch = false; 

    if (arr.size() % 2 != 0)
    {
        saved = arr.back();
        arr.pop_back();
        snitch = true;
    }
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            std::swap(arr[i], arr[i + 1]);
        }
    }
    std::vector<int> mainChain;
    std::vector<int> pend;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        mainChain.push_back(arr[i + 1]);
        pend.push_back(arr[i]);
    }
    sortVector(mainChain);

    for (size_t i = 0; i < pend.size(); i++)
    {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
        mainChain.insert(it, pend[i]);
    }
    if (snitch)
    {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), saved);
        mainChain.insert(it, saved);
    }
    arr = mainChain;
}

void PmergeMe::sortDeque(std::deque<int> &arr)
{
	    if (arr.size() <= 1)
        return;
    int saved = -1;
    bool snitch = false; 

    if (arr.size() % 2 != 0)
    {
        saved = arr.back();
        arr.pop_back();
        snitch = true;
    }
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            std::swap(arr[i], arr[i + 1]);
        }
    }
    std::deque<int> mainChain;
    std::deque<int> pend;
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        mainChain.push_back(arr[i + 1]);
        pend.push_back(arr[i]);
    }
    sortDeque(mainChain);

    for (size_t i = 0; i < pend.size(); i++)
    {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i]);
        mainChain.insert(it, pend[i]);
    }
    if (snitch)
    {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), saved);
        mainChain.insert(it, saved);
    }
    arr = mainChain;
}

void PmergeMe::process(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error" << std::endl;
        return;
    }
    for (int i = 1; i < ac; i++)
    {
        std::string str = av[i];

        for (size_t j = 0; j < str.length(); j++)
        {
            if (!isdigit(str[j]))
            {
                std::cout << "Error" << std::endl;
                return;
            }
        }
        long num = std::atol(av[i]);
        if (num > 2147483647)
        {
            std::cout << "Error" << std::endl;
            return;
        }
        this->_vector.push_back(static_cast<int>(num));
        this->_deque.push_back(static_cast<int>(num));
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++)
    {
        std::cout << this->_vector[i] << " ";
    }
    std::cout << std::endl;

    struct timeval start, end;

    gettimeofday(&start, NULL);
    sortVector(this->_vector);
    gettimeofday(&end, NULL);
    double timeVec = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
	
	gettimeofday(&start, NULL);
    sortDeque(this->_deque);
    gettimeofday(&end, NULL);

	double timeDeq = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
    
	std::cout << "After:  ";
    for (size_t i = 0; i < this->_vector.size(); i++)
    {
        std::cout << this->_vector[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << this->_vector.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_deque.size()
              << " elements with std::deque : "
              << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
}