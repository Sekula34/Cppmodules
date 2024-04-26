#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void):_comparisonCounter(0)
{

}

PmergeMe::PmergeMe(const PmergeMe& source)
{
	(void) source;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& source)
{
	(void) source;
	return (*this);
}

PmergeMe::~PmergeMe()
{

}

unsigned int PmergeMe::getComparisonCounter(void) const 
{
	return (_comparisonCounter);
}
