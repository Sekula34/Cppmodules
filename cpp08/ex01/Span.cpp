#include "Span.hpp"
#include <iostream>
#include <cstdlib>

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

void Span::addManyNumbers(void)
{
	void srand();
	while(myVector.size() < N)
	{
		int randomNum = rand() % 1000;
		myVector.push_back((randomNum));
	}
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
