#include "PmergeMe.hpp"
#include <exception>
#include <iostream>
#include <vector>

void printVec(std::vector<int>& vec)
{
	std::cout << "Vector values are :" << std::endl;
	for(std::vector<int>::iterator it =vec.begin(); it != vec.end(); it ++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void printPair(pair onePair)
{
	std::cout << "A [bigger value] is " << onePair.a << std::endl;
	std::cout << "B [smaller value] is " << onePair.b << std::endl;
	std::cout << "-------------------------------------" << std::endl; 
}


void testingBInsertSequence()
{
	PmergeMe object;
	//make it public to test outside main
	//std::vector<int> bInsertSeq = object._getBInsertSequence(10, false);
	//printVec(bInsertSeq);
}

void testingJohnson(std::vector<int>& myVector)
{
	PmergeMe merge;
	merge.mergeInsertSort(myVector);
	printVec(merge.sortedVec);
	std::cout <<"Number of comparison is " << merge.getComparisonCounter() << std::endl;
	return;
}


int main()
{
	try 
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
		//testingBInsertSequence();
		//merge.printSortedVec();
		std::vector<int>baseCase;
		baseCase.push_back(3);
		baseCase.push_back(2);
		baseCase.push_back(1);
		testingJohnson(baseCase);

	}
	catch(std::exception &e)
	{
		std::cerr <<"EXCEPTION CATCHED" <<std::endl;
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
