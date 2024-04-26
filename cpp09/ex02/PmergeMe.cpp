#include "PmergeMe.hpp"
#include <algorithm>
#include <vector>

unsigned int PmergeMe::_comparisonCounter = 0;

PmergeMe::PmergeMe(void)
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

//prerequiste for this is sorted vector
//finds position where to insert value, and count the number of comparisons
//insrt value
//Maybe will need some modificaton that will tell end iterator for looking
void PmergeMe::_binaryInsertion(int valueToInsert, std::vector<int>& vec)
{
	if(vec.size() == 0)
	{
		vec.insert(vec.begin(), valueToInsert);
		return;
	}
	std::vector<int>::iterator Positon = std::lower_bound(vec.begin(), vec.end(), valueToInsert,Compare());

	vec.insert(Positon, valueToInsert);
	return;
}


unsigned int PmergeMe::getComparisonCounter(void) const 
{
	return (_comparisonCounter);
}
