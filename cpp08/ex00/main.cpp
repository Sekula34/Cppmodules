#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{

	std::vector<int> myVector(10, 1);
	std::vector<int>::iterator myIterator;
	try 
	{
		myIterator = easyfind(myVector, 2);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	std::cout << *myIterator <<std::endl;
	return (0);
}
