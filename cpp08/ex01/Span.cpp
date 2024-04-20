#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <cmath>

//find smallestDiffernce beetween two elem in vector
//prerequisite atleast two elements and sorted vector
//return smallest differnce in vector
int Span::_findSmallestDiff()
{
	myIterator firstElem;
	myIterator secondElem;
	int smallestDiff(0);

	for(firstElem = myVector.begin(); firstElem < myVector.end() - 1; firstElem++)
	{
		secondElem = firstElem + 1;
		if(firstElem == myVector.begin())
			smallestDiff = std::abs(*firstElem - *secondElem);
		else
		{
			int currentDiff = std::abs(*firstElem - *secondElem);
			if(currentDiff < smallestDiff)
				smallestDiff = currentDiff;
		}
	}
	return (smallestDiff);
}

Span::Span(void) : N(0)
{

}

Span::Span(unsigned int n) : N(n)
{

}

Span::Span(const Span& source) : N(source.N)
{
	this->myVector = source.myVector;
}

Span& Span::operator=(const Span& source) 
{
	this->N = source.N;
	this->myVector = source.myVector;
	return (*this);
}

Span::~Span()
{

}

// This class will have a member function called addNumber() to add a single number
// to the Span. It will be used in order to fill it. Any attempt to add a new element if there
// are already N elements stored should throw an exception.
void Span::addNumber(int number)
{
	if(myVector.size() == N)
		throw SpanOverflowException();
	myVector.push_back(number);
}

// Last but not least, it would be wonderful to fill your Span using a range of iterators.
// Making thousands calls to addNumber() is so annoying. Implement a member function
// to add many numbers to your Span in one cal
void Span::addManyNumbers(myIterator begin, myIterator end)
{
	unsigned int sizeToAdd = end - begin;
	if(sizeToAdd + myVector.size() > N)
		throw SpanOverflowException();
	myVector.insert(myVector.end(), begin, end);
}

//find out the shortest span
//throw TooSmallForSpanException if there is not 2 elements
//sorts vector and return smallest difference beetween two elements
int Span::shortestSpan()
{
	if(myVector.size() < 2)
		throw TooSmallForSpanException();
	std::sort(myVector.begin(), myVector.end());
	myIterator it;
	it = std::adjacent_find(myVector.begin(), myVector.end());
	if(it != myVector.end())
		return (0);
	return (_findSmallestDiff());
}
//find longest span aka difference between max and min element
//throw TooSmallForSpanException if there is not at least two elements in vector
int Span::longestSpan()
{
	if(myVector.size() < 2)
		throw TooSmallForSpanException();
	myIterator max = std::max_element(myVector.begin(), myVector.end());
	myIterator min = std::min_element(myVector.begin(), myVector.end());
	return (std::abs(*max - *min));
}


void Span::printVector(void) const
{
	for(std::vector<int>::const_iterator it = myVector.begin(); it != myVector.end(); ++it)
    {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
}


const char* Span::SpanOverflowException::what() const throw()
{
	return ("Span is full exception");
}

const char* Span::TooSmallForSpanException::what() const throw()
{
	return ("There is not enough element to find span. At least 2 elements needed");
}
