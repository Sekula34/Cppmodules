#include "Span.hpp"
#include <iostream>


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
	a.addManyNumbers();
	a.printVector();
}

int main()
{
	try
	{
		test1();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
