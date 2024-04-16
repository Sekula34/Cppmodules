#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <iostream>


Base* generate(void)
{
	Base * ptrReturn;
	std::srand(std::time(NULL));
	int randomNum = std::rand() % 3;
	switch(randomNum)
	{
		case 0:
		{
			ptrReturn = new A();
			break;
		}
		case 1:
		{
			ptrReturn = new B();
			break;
		}
		case 2:
		{
			ptrReturn = new C();
			break;
		}
		default :
			throw std::runtime_error("Something went wrong");
	}
	return (ptrReturn);

}

void identify(Base *p)
{
	A* aPtr;
	B* bPtr;
	C* cPtr;

	aPtr = dynamic_cast<A*>(p);
	if(aPtr != NULL)
	{
		std::cout << "Actual type of object is: A" << std::endl;
		return;
	}
	bPtr = dynamic_cast<B*>(p);
	if(bPtr != NULL)
	{
		std::cout << "Actual type of object is: B" << std::endl;
		return;
	}
	cPtr = dynamic_cast<C*>(p);
	if(cPtr != NULL)
	{
		std::cout <<"Actual type of object is: C" << std::endl;
		return;
	}
	std::runtime_error("None of the A B or C");

}

void identfy(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout <<"(REF) Actual type of object is: A" << std::endl;
		return;
	}
	catch (std::exception& e)
	{
		try 
		{
			(void)dynamic_cast<B&>(p);
			std::cout <<"(REF) Actual type of object is: B" << std::endl;
			return;
		}
		catch(std::exception& e)
		{
			(void)dynamic_cast<C&>(p);
			std::cout <<"(REF) Actual type of object is: C" << std::endl;
			return;
		}
	}
}

int main()
{
	try 
	{
		Base* myPtr;
		myPtr = generate();
		Base& ref = *myPtr;
		std::cout << myPtr << std::endl;
		identify(myPtr);
		identfy(ref);
		delete myPtr;
	}
	catch(std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
