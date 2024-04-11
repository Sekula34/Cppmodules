#include <exception>
#include <iostream>
#include "Array.hpp"


class myClass
{
	public:
		int a;
		double b;
};

int main()
{
	try 
	{

		Array<myClass> myArray(5);
	 	myClass value = myArray[100];
		std::cout << value.a <<std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	// int * a = new int();
	// std::cout << *a << std::endl;
	return (0);
}
