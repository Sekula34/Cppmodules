#include "Span.hpp"
#include <iostream>
#include <cstdlib>

void fillVector(std::vector<int>& vec, int numberOfValues)
{
	for(int i = 0; i < numberOfValues; i++)
	{
		void srand();
		vec.push_back(rand() %1000 );
	}
}

//testing printing and exception
void test0()
{
	Span a(2);
	a.addNumber(1);
	a.addNumber(2);
	a.printVector();
}

void test1()
{
	Span a(100);
	std::vector<int> toAdd;
	fillVector(toAdd, 100);
	a.addManyNumbers(toAdd.begin(), toAdd.end());
	a.printVector();
}

//testing smalles span
//throw exception. There is max of 100 elems but there is not two elems needded
void test2()
{
	Span a(100);
	std::cout << a.shortestSpan() << std::endl;
}

//subject main for shortest span
void test3()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
}

int main()
{
	try
	{
		//test1();
		//test2();
		test3();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
