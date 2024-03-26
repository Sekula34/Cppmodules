#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

//too high
void test1()
{
	try 
	{
		Bureaucrat a("Ime", 167);
	}
	catch (std::exception &e)
	{
		std::cout <<e.what() << std::endl;;
		throw ;
	}
}

//too low
void test2()
{
	try 
	{
		Bureaucrat b("Filip", -67);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		throw ;
	}
}

//geter functions

void test3()
{
	Bureaucrat biro;
	std::cout << "My name is " << biro.getName() << std::endl;
	std::cout << "My grade is " << biro.getGrade() << std::endl;
	//error throw in this case

	// Bureaucrat filip("filip", 70000);
	// std::cout << "My name is "<< filip.getName() << std::endl;
	// std::cout << "My grade is " << filip.getGrade() << std::endl;
}

int main()
{
	try
	{
		test1();
		// test2();
		test3();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	std::cout << "Something after main" << std::endl;
	std::cout << "Everything is good" << std::endl; 
	return 0;
}
