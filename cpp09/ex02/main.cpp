#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <ctime>
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>


void printVec(std::vector<int>& vec)
{
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it ++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void printQue(std::deque<int>& list)
{
	if(list.empty())
		std::cout << "lista je prazna";
	for(std::deque<int>::iterator it =list.begin(); it != list.end(); it ++)
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
			throw std::runtime_error("Error");
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

//check if number of argumetns are correct, put value in user vector
void getUserInputQue(int argc, char** argv, std::deque<int>& userVector)
{
	if(argc == 1)
		throw std::runtime_error("User didnt provide any input for mergeInsertSort");
	for(int i = 1; i < argc; i++)
	{
		int value = getIntfromString(argv[i]);
		userVector.push_back(value);
	}
}



void checkSorted(std::vector<int> &vec, std::deque<int> deque, std::vector<int> input)
{
	std::vector<int>::iterator first = vec.begin();
	for(std::vector<int>::iterator it = first+1; it != vec.end(); it++)
	{
		if(*it < *first)
		{
			std::cout << *it << " " << *first << std::endl;
			std::cerr<<"Vec not sorted" << std::endl;
		}
		first++;
	}
	std::deque<int>::const_iterator it = deque.begin();
	if(it == deque.end())
	{
		return ;
	}
	int prev = *it;
	for(; it != deque.end(); ++it)
	{
		if(*it < prev)
		{
			std::cerr<<"deque not sorted" << std::endl;
		}
		prev = *it;
	}
	if(vec.size() != input.size() || deque.size() != input.size())
		throw std::runtime_error("element size is not correct");
}

void checkForDuplicates(std::vector<int> duplicateCheck)
{
	std::sort(duplicateCheck.begin(), duplicateCheck.end());
	if(std::adjacent_find(duplicateCheck.begin(), duplicateCheck.end()) != duplicateCheck.end())
	{
		throw std::runtime_error("Found duplicates in user input. They are not handled in sorting");
	}
	return;

}

void subjectOutput(int argc, char** argv)
{
	PmergeMe johnsonSort;
	std::vector<int> userVector;
	std::deque<int> userQue;
	std::vector<int> duplicateCheck;
	
	getUserInput(argc, argv, duplicateCheck);
	checkForDuplicates(duplicateCheck);

	std::cout <<"Before: ";
	printVec(duplicateCheck);


	clock_t startVec = std::clock();
	getUserInput(argc, argv, userVector);
	johnsonSort.mergeInsertSort(userVector);
	clock_t endVec = std::clock();
	double elapsed_time = static_cast<double>(endVec- startVec) / CLOCKS_PER_SEC;
	std::cout <<"After: ";
	printVec(johnsonSort.sortedVec);
	std::cout << "Time to process a range of "<< userVector.size() <<" elements with std::vector : ";
	std::cout <<elapsed_time * 1000000<<" μs" << std::endl;

	std::cout <<"Number of comparison " << johnsonSort.getComparisonCounter() << std::endl;
	
	PmergeMe dequeSort;
	startVec = std::clock();
	getUserInputQue(argc, argv, userQue);
	dequeSort.mergeInsertQue(userQue);
	// std::cout << "size of deque is " << dequeSort.sortedQue.size() << std::endl;
	// std::cout << "size of vector is " << johnsonSort.sortedVec.size() << std::endl;
	endVec = std::clock();
	elapsed_time = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
	//printQue(dequeSort.sortedQue);
	std::cout << "Time to process a range of "<< userVector.size() <<" elements with std::deque : ";
	std::cout << elapsed_time * 1000000<<" μs" << std::endl;
	checkSorted(johnsonSort.sortedVec, dequeSort.sortedQue, userVector);
}


int main(int argc, char **argv)
{
	try 
	{
		subjectOutput(argc, argv);

	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
