#include "Span.hpp"
#include <iostream>

int main()
{
	try
	{
		Span a(2);
		a.addNumber(1);
		a.addNumber(2);
		a.printVector();

	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
