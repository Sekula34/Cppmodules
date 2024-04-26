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


void testingBInsertSequence()
{
	PmergeMe object;
	std::vector<int> bInsertSeq = object._getBInsertSequence(10, false);
	printVec(bInsertSeq);
}


int main()
{
	PmergeMe merge;
	std::vector<int> myVector;
	myVector.push_back(2);
    myVector.push_back(4);
    myVector.push_back(6);
    myVector.push_back(8);
    myVector.push_back(10);
    myVector.push_back(12);
    myVector.push_back(14);
    myVector.push_back(16);
    myVector.push_back(18);
    myVector.push_back(20);
    myVector.push_back(22);
    myVector.push_back(24);
    myVector.push_back(26);

	//std::cout << "I am here " << std::endl;
	std::cout << "Comparison counter is "<<merge.getComparisonCounter() << std::endl;
	//merge._binaryInsertion(3, myVector);
	std::cout <<"Comparison counter after is " << merge.getComparisonCounter() << std::endl;
	// for(int i = 0; i < 10; i ++)
	// {
	// 	std::cout << merge._getJacobsthalNumber(i) << std::endl;
	// }
	testingBInsertSequence();
	//printVec(myVector);
	return 0;
}
