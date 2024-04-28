#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cmath>



// Function to calculate the factorial of a number
unsigned  long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    unsigned  long fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Function to calculate log2(n!)
double log2Factorial(int n) {
    double result = 0.0;
    for (int i = 1; i <= n; ++i) {
        result += log2((double)i);
    }
    return result;
}

void minCompneeded(int n)
{
	int minCompNumber;
	minCompNumber = log2Factorial(n);
	std::cout << "Min comp needed " << minCompNumber << std::endl;
}
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
	std::cout << "Unsorted values are ";
	printVec(myVector);
	merge.mergeInsertSort(myVector);
	printVec(merge.sortedVec);
	std::cout <<"Number of comparison is " << merge.getComparisonCounter() << std::endl;
	minCompneeded(myVector.size());
	return;
}


//goes through one char** argv and check if evertyhing is digit
//throw exception if something that is not digit is found 
//check if one arg size is bigger than 10 if so throw exception
//lastly try to put it in int from stringstream, throw exception if failed - should not happed
int getIntfromString(std::string oneArg)
{
	int value;
	//std::cout << "One arg as string is " << oneArg << std::endl;
	for(size_t i = 0; i < oneArg.size(); i++)
	{
		if(!std::isdigit(oneArg[i]) )
		{
			std::cerr<<"Invalid argument :" << oneArg << std::endl;
			throw std::runtime_error("Found something that is not digit in input");
		}
	}
	if(oneArg.size() > 10)
		throw std::runtime_error("Argument is bigger than 10 chars which will cause int overflow if converted");
	if(oneArg.size() == 10 && oneArg > "2147483647")
		throw std::runtime_error("User tried to put integer bigger than MAXINT 2147483647 ");
	std::stringstream ss(oneArg);
	if( !(ss >> value))
		throw std::runtime_error("StringStream in getIntFromString failed");
	return value;
}
//check if number of argumetns are correct, put value in user vector
void getUserInput(int argc, char** argv, std::vector<int>& userVector)
{
	if(argc == 1)
		throw std::runtime_error("User didnt provide any input for mergeInsertSort");
	for(int i = 1; i < argc; i++)
	{
		int value = getIntfromString(argv[i]);
		userVector.push_back(value);
	}
}


int main(int argc, char **argv)
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
		//std::cout << "Comparison counter is "<<merge.getComparisonCounter() << std::endl;
		//merge._binaryInsertion(3, myVector);
		//std::cout <<"Comparison counter after is " << merge.getComparisonCounter() << std::endl;
		// for(int i = 0; i < 10; i ++)
		// {
		// 	std::cout << merge._getJacobsthalNumber(i) << std::endl;
		// }
		//testingBInsertSequence();
		//merge.printSortedVec();
		std::vector<int>userVector;
		std::vector<int>baseCase;
		baseCase.push_back(6);
		baseCase.push_back(8);
		baseCase.push_back(3);
		std::vector<int> nonBaseCase;
		nonBaseCase.push_back(16);
		nonBaseCase.push_back(15);
		nonBaseCase.push_back(12);
		nonBaseCase.push_back(13);
		nonBaseCase.push_back(5);

		nonBaseCase.push_back(7);
		nonBaseCase.push_back(2);
		nonBaseCase.push_back(6);
		nonBaseCase.push_back(19);
		nonBaseCase.push_back(20);

		nonBaseCase.push_back(1);
		nonBaseCase.push_back(21);
		nonBaseCase.push_back(3);
		nonBaseCase.push_back(11);
		nonBaseCase.push_back(4);

		nonBaseCase.push_back(10);
		nonBaseCase.push_back(9);
		nonBaseCase.push_back(18);
		nonBaseCase.push_back(17);
		nonBaseCase.push_back(14);

		nonBaseCase.push_back(8);
		// nonBaseCase.push_back(3);
		// nonBaseCase.push_back(10);
		// nonBaseCase.push_back(4);
		// nonBaseCase.push_back(1);

		getUserInput(argc, argv, userVector);
		testingJohnson(userVector);
		

	}
	catch(std::exception &e)
	{
		std::cerr <<"EXCEPTION CATCHED" <<std::endl;
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
