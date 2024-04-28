#include "PmergeMe.hpp"
#include <cctype>
#include <cstddef>
#include <ctime>
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <sys/time.h>



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
	minCompNumber = log2Factorial(n) + 1;
	std::cout << "Min comp needed " << minCompNumber << std::endl;
}
void printVec(std::vector<int>& vec)
{
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

 long getTimeInMicroseconds() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * 1000000L + currentTime.tv_usec;
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

    // Convert seconds to microseconds (1 second = 1,000,000 microseconds)

	std::cout <<"After: ";
	printVec(johnsonSort.sortedVec);
	std::cout << "Time to process a range of "<< userVector.size() <<" elements with std::vector : ";
	std::cout << endTime - startTime <<" μs" << std::endl;
}


int main(int argc, char **argv)
{
	try 
	{
		subjectOutput(argc, argv);
		//testingJohnson(userVector);

	}
	catch(std::exception &e)
	{
		std::cerr <<"EXCEPTION CATCHED" <<std::endl;
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
