#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <ostream>
#include "Form.hpp"

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


//decrease grade exception and << overload
void test4()
{
	Bureaucrat filip("filip", 150);
	std::cout << filip << std::endl;
	filip.decreaseGrade();
	std::cout << "This will not be printed if exception is thrown" << std::endl;
}

//increase grade exception and << overload
void test5()
{
	Bureaucrat filip("filip", 1);
	std::cout << filip << std::endl;
	filip.increaseGrade();
	std::cout << "This will not be printed if exception is thrown" << std::endl;
}

//increase and decrease overload
void test6()
{
	Bureaucrat filip("filip", 12);
	filip.decreaseGrade(5);
	std::cout << filip << std::endl;
	//filip.decreaseGrade(200);
	filip.increaseGrade(19);
}

void test7()
{
	Form first;
	std::cout << first << std::endl;
}

int main()
{
	try
	{
		//test1();
		// test2();
		//test3();
		//test4();
		//test5();
		//test6();
		//--------exo1//
		test7();

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
