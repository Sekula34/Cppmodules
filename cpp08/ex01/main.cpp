#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void fillVector(std::vector<int>& vec, int numberOfValues)
{
	for(int i = 0; i < numberOfValues; i++)
	{
		vec.push_back(rand());
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
//same as test2 but with longestSpan
void test2a()
{
	Span a(100);
	std::cout << a.longestSpan() << std::endl;
}

//subject main for shortest span and longest span
void test3()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test4()
{
	Span a(12 * 1000);
	std::vector<int> filler;
	fillVector(filler, (12 * 1000));
	a.addManyNumbers(filler.begin(), filler.end());
	std::cout << a.shortestSpan() << std::endl;
	std::cout << a.longestSpan() << std::endl;
	//a.printVector();
}

int main()
{
	try
	{
		std::srand(static_cast<unsigned int>(std::time(0)));
		//test1();
		//test2();
		//test2a();
		//test3();
		test4();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
