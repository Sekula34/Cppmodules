#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <ctime>
#include <exception>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <sys/time.h>


void printVec(std::vector<int>& vec)
{
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it ++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void printList(std::list<int>& list)
{
	if(list.empty())
		std::cout << "lista je prazna";
	for(std::list<int>::iterator it =list.begin(); it != list.end(); it ++)
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

long getTimeInMicroseconds()
{
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return (currentTime.tv_sec * 1000000L + currentTime.tv_usec);
}

void checkSorted(std::vector<int> &vec, std::list<int> list)
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
	std::list<int>::const_iterator it = list.begin();
	if(it == list.end())
	{
		return ;
	}
	int prev = *it;
	for(; it != list.end(); ++it)
	{
		if(*it < prev)
		{
			std::cerr<<"List not sorted" << std::endl;
		}
		prev = *it;
	}
}

void subjectOutput(int argc, char** argv)
{
	PmergeMe johnsonSort;
	std::vector<int> userVector;
	getUserInput(argc, argv, userVector);

	std::cout <<"Before: ";
	printVec(userVector);
	time_t startTime = getTimeInMicroseconds();
	johnsonSort.mergeInsertSort(userVector);
	time_t endTime = getTimeInMicroseconds();
	std::cout <<"After: ";
	printVec(johnsonSort.sortedVec);
	std::cout << "Time to process a range of "<< userVector.size() <<" elements with std::vector : ";
	std::cout << endTime - startTime <<" μs" << std::endl;

	std::cout <<"Number of comparison" << johnsonSort.getComparisonCounter() << std::endl;
	PmergeMe listSort;
	time_t listStartTime = getTimeInMicroseconds();
	listSort.mergeInsertSort(userVector,true);
	time_t listEndTime = getTimeInMicroseconds();
	std::cout << "Time to process a range of "<< userVector.size() <<" elements with std::list : ";
	std::cout << listEndTime - listStartTime <<" μs" << std::endl;
	checkSorted(johnsonSort.sortedVec, listSort.sortedList);
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
