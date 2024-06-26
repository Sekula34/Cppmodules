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

//proving that << works for form
void test7()
{
	Form first;
	std::cout << first << std::endl;

	Form second("Forma2",100,80);
	std::cout <<second << std::endl;
}

//grades outside range in constructor
void test8()
{
	Form first("forma", 6, 1);
	std::cout << "this shall not be printed if there is error" << std::endl;
	std::cout << first << std::endl;
}

//testing besignedfunction.
//as long as formgrade is higher it will be possible to sing
void test9(int formgrade, int biroGrade)
{
	Form formToSing("Prijava", formgrade, 90);
	Bureaucrat biros("Pera", biroGrade);
	std::cout << formToSing << std::endl;
	formToSing.beSigned(biros);
	std::cout << "Form info after signing" << std::endl;
	std::cout << formToSing << std::endl;
}


//testing signFrom function
//form will be signed if biro is higher or equal grade(lower int)
void test10(int formgrade, int biroGrade)
{
	Bureaucrat chef("Herr MR CHEF DR SC PHD", biroGrade);
	Form report("Report", formgrade, formgrade);
	std::cout << "Form before signing" << std::endl;
	std::cout << report << std::endl;
	chef.signForm(report);
	std::cout << "Form after signing" << std::endl;
	std::cout << report << std::endl;
}

//if form is already signed
void test11(int formgrade, int biroGrade)
{
	Bureaucrat chef("Herr MR CHEF DR SC PHD", 1);
	Bureaucrat poorGuy("Poorguy", biroGrade);
	Form report("Report", formgrade, formgrade);
	chef.signForm(report);
	std::cout << "Form before signing" << std::endl;
	std::cout << report << std::endl;
	poorGuy.signForm(report);
	std::cout << "Form after signing" << std::endl;
	std::cout << report << std::endl;
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
		//test7();
		//test8();
		//test9(700,2000);
		test10(12, 9);
		//test11(1, 1);

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
