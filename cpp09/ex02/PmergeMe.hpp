#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <sys/time.h>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::deque<int> _deque;
	void sortVector(std::vector<int> &arr);
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

	void process(int argc, char **argv);
};


#endif