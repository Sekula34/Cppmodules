#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <vector>
#include <iostream>

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

//function that takes unsored vec of int and makes pair of them
//return the list of all pairs.
//if number of elements in unsored vec is odd
//last pair have value a set to -1, and b is last element of vector
std::vector<pair> PmergeMe::_getUnsortedPairs(std::vector<int> unsortedVec)
{
	std::vector<pair> toReturn;
	bool odd = (unsortedVec.size() % 2);
	size_t numberOfPairs = unsortedVec.size() / 2;
	pair onePair;
	int j = 0;
	for(size_t i = 0; i < numberOfPairs; j += 2, i++)
	{
		onePair = _makeOnePair(unsortedVec[j], unsortedVec[j + 1]);
		toReturn.push_back(onePair);
	}
	if(odd == true)
	{
		onePair = _makeOnePair(*(unsortedVec.end() - 1));
		toReturn.push_back(onePair);
	}
	return (toReturn);
}


//b3,b2; b5,b4; b11,b10, ... ,b5; ... ; btk,btk-1, ... ,btk-1+1; 
//function that creates and retunr the sequence of indexes in which b should be inserted in a
//size of that vector is always the same size as number of pairs
//only if last b dont have pair it the size is increased by one
std::vector<int> PmergeMe::_getBInsertSequence(int numberOfPairs, bool lastBAlone)
{
	if(numberOfPairs < 1)
		throw std::runtime_error("_getBInsertSequence is called on less than 1 pair");
	size_t sequenceSize(numberOfPairs);
	if(lastBAlone)
		sequenceSize++;
	std::vector<int> indexSequence;
	indexSequence.push_back(1);
	if(sequenceSize == 1)
		return indexSequence;
	if(sequenceSize == 2)
	{
		indexSequence.push_back(2);
		return indexSequence;
	}
	else
	{
		indexSequence.push_back(3);
		indexSequence.push_back(2);
	}
	_insertRestOfSequence(indexSequence, sequenceSize);
	return (indexSequence);
}
// return n-th member of JacobsthalNumber
//n 0 = 0
//n 1 = 1;
//n n = n- 1 * 2(n-2)
//0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691,
//throws runtimeerror if N is more than 20 for potenital crash reasons
unsigned int PmergeMe:: _getJacobsthalNumber(int n)
{
	if(n > 20)
		throw std::runtime_error("JacobsthalNumber bigger than 20 could trigger stackOverflow");
	if(n == 0)
		return (0);
	if (n == 1)
		return (1);
	unsigned int oneBeforeN = _getJacobsthalNumber(n - 1);
	unsigned int twoBeforeN = _getJacobsthalNumber(n - 2);
	return (oneBeforeN +  (2 * twoBeforeN) );
}

//function that feesl bsequence vector with numbers until it reaches the final size
//it start with jacob number 5 and try to insert in in vector
//order 5,4,11,10,9.....
//if size is smaller that much jacobNumbers are discard
//example final size is 4, but jacob numbers are 
//1 3 2,    5 is discarded and 4 is put
void PmergeMe::_insertRestOfSequence(std::vector<int>& bSequence, size_t finalSizeOfVector)
{
	int nMemberOfJacobSequence = 4; // Jacob sequence start with 5 J(4) = 5
	unsigned int lastJacobNumber = 3;
	unsigned int neuJacobNumber = _getJacobsthalNumber(nMemberOfJacobSequence); //ne number 5
	size_t numberOfCurrentInserts = neuJacobNumber - lastJacobNumber; //will try to insert 2 numbers
	size_t freeSize = finalSizeOfVector - bSequence.size();
	while(bSequence.size() != finalSizeOfVector)
	{
		while(numberOfCurrentInserts > freeSize)
		{
			neuJacobNumber --;
			numberOfCurrentInserts --;
		}
		bSequence.push_back(neuJacobNumber);
		freeSize--;
		neuJacobNumber--;
		numberOfCurrentInserts--;
		if(numberOfCurrentInserts == 0 && freeSize > 0)
		{
			lastJacobNumber = _getJacobsthalNumber(nMemberOfJacobSequence);
			nMemberOfJacobSequence ++;
			neuJacobNumber = _getJacobsthalNumber(nMemberOfJacobSequence);
			numberOfCurrentInserts = neuJacobNumber - lastJacobNumber;
		}
	}
}

//function that takes two values and return pair
//bigger value is putted in .a while smaller is always in .b
//function have overload if only one value is provided than that value is in .b
//a in that case is undefinded
pair PmergeMe::_makeOnePair(int value1, int value2)
{
	pair onePair;
	_comparisonCounter++;
	if(value1 > value2)
	{
		onePair.a = value1;
		onePair.b = value2;
	}
	else
	{
		onePair.a = value2;
		onePair.b = value1;
	}
	return onePair;
}
//overload
//function that takes two values and return pair
//bigger value is putted in .a while smaller is always in .b
//function have overload if only one value is provided than that value is in .b
//a in that case is -1 (value set to not trigger conditional jump, but should not be used)
pair PmergeMe::_makeOnePair(int valueB)
{
	pair OnePair;
	OnePair.a = -1;
	OnePair.b = valueB;
	return OnePair;
}



void PmergeMe::mergeInsertSort(std::vector<int> unsortedVec)
{
	if(unsortedVec.size() < 2)
		throw std::runtime_error("Called merge Insert with less than 2 elements");
	int numberOfPairs = unsortedVec.size()/2;
	std::vector<pair> unsortedPairs;
	std::cout << "Number of pairs is " << numberOfPairs <<" and size of vec is " << unsortedVec.size() << std::endl;
	return;
}

unsigned int PmergeMe::getComparisonCounter(void) const 
{
	return (_comparisonCounter);
}


void PmergeMe::printSortedVec(void)
{
	if(sortedVec.empty())
		throw std::runtime_error("Sorted vec is empty");
	std::vector<int>::iterator it;
	for(it = sortedVec.begin(); it != sortedVec.end(); it++)
	{
		std::cout << *it;
		if(it + 1 != sortedVec.end())
			std::cout <<", ";
	}
	std::cout << std::endl;
}
