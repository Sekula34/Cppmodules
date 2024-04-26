#include "PmergeMe.hpp"
#include <iostream>
#include <vector>

void printVec(std::vector<int>& vec)
{
	for(std::vector<int>::iterator it =vec.begin(); it != vec.end(); it ++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main()
{
	PmergeMe merge;
	std::vector<int> myVector;
	myVector.push_back(1);
	myVector.push_back(3);
	myVector.push_back(5);
	myVector.push_back(7);

	std::cout << "I am here " << std::endl;
	std::cout << "Comparison counter is "<<merge.getComparisonCounter() << std::endl;
	merge._binaryInsertion(4, myVector);
	std::cout <<"Comparison counter after is " << merge.getComparisonCounter() << std::endl;
	printVec(myVector);
	return 0;
}
