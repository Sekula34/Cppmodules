#include "AMateria.hpp"
#include "Character/Character.hpp"
#include "Ice/Ice.hpp"
#include "Cure/Cure.hpp"
#include <iostream>


void prinTest(std::string number)
{
	std::cout <<"----------Test " << number << "----------" << std::endl;
}

void printEnd(void)
{
	std::cout<<"--------------------------" << std::endl;
}

//test for setting ptr to be clone of Ice that you need to free later
void test1(AMateria** ptr)
{
	prinTest("1");
	{
		Ice led;
		*ptr = led.clone();
		std::cout << (*ptr)->getType() << std::endl;
	}
	printEnd();
}
 
//same as test1 but for setting ptr to be clone of Cure that you need to free later
void test2(AMateria** ptr)
{
	prinTest("2");
	{
		Cure lijek;
		*ptr = lijek.clone();
		std::cout << (*ptr)->getType() << std::endl;
		//delete ptr;
	}
	printEnd();	
}

//printng type of ptr first after calling test 1 then after calling test 2
//to show that ptr can be both Cure and Ice
//ptr is freed here and cannot be accessed later
void test3(AMateria** ptr)
{
	prinTest("3");
 	test1(ptr);
	std::cout << "Ptr type after test is " << (*ptr)->getType() << std::endl;
	delete *ptr; 
	test2(ptr);
	std::cout << "Ptr type after test is " << (*ptr)->getType() << std::endl;
	delete *ptr;
	*ptr = NULL;
	printEnd();
}

//test that shows creation and destruction of Character class
void test4(void)
{
	prinTest("4");
	{
		AMateria *icePtr;
		icePtr = new Ice();
		Character filip("filip");
		filip.equip(icePtr);
		std::cout << "My name is " << filip.getName() << std::endl;
		filip.listAllMaterials();
		AMateria *toDelete;
		toDelete = filip.getMateriaPtr(0);
		filip.unequip(0);
		filip.listAllMaterials();
		delete toDelete;
		//delete icePtr;
	}
	printEnd();
}

//test for showing use function of character
void test5(void)
{
	prinTest("5");
	{
		Character Bobo("Bobo");
		Character enemy("Enemy");
		Character ally("BUBOO");
		AMateria *icePtr = new Ice();
		AMateria *curePtr = new Cure();

		Bobo.equip(icePtr);
		Bobo.equip(curePtr);
		Bobo.listAllMaterials();
		Bobo.use(0, enemy);
		Bobo.use(1, ally);
		Bobo.use(10, enemy);
		Bobo.use(2, ally);

		delete icePtr;
		delete curePtr;
	}
	printEnd();
}

int main()
{
	// AMateria *ptr = NULL;
	// test3(&ptr);
	// delete ptr;
	// test4();
	test5();
	return (0);
}
