#include "easyfind.hpp"
#include <vector>
#include <iostream>



//test that try to find 1 which exist
void test1()
{
	std::vector<int> myVector(10, 1);
	std::vector<int>::iterator myIterator;
	try 
	{
		myIterator = ::easyfind(myVector, 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
	std::cout << *myIterator <<std::endl;
}

//test that try to find 2 which does not exist
void test2()
{
	std::vector<int> myVector(10, 1);
	std::vector<int>::iterator myIterator;
	try 
	{
		myIterator = ::easyfind(myVector, 2);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
	std::cout << *myIterator <<std::endl;
}

//test that try to find pushback value which does not exist
void test3()
{
	std::vector<int> myVector(10, 1);
	myVector.push_back(78);
	myVector.push_back(17);
	std::vector<int>::iterator myIterator;
	try 
	{
		myIterator = ::easyfind(myVector, 78);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return;
	}
	std::cout << *myIterator <<std::endl;
}

int main()
{
	try 
	{
		test1();
		test2();
		test3();
	}
	catch (std::exception &e)
	{
		std::cerr << "Something bad happpend" << e.what() << std::endl;
		return (1);
	}
	return (0);
}
