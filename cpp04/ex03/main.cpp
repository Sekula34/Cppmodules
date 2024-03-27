#include "AMateria.hpp"
#include "Character/Character.hpp"
#include "Ice/Ice.hpp"
#include "Cure/Cure.hpp"
#include <iostream>
#include "MateriaSource/IMateriaSource.hpp"
#include "MateriaSource/MateriaSource.hpp"


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

		// delete icePtr;
		// delete curePtr;
	}
	printEnd();
}


//Test for deep copy of charcter
void test6(void)
{
	prinTest("6");
	{
		Character Bobo("Bubimir6");
		Bobo.equip(new Ice());
		Bobo.equip(new Cure());
		Character Bobo2(Bobo);
		AMateria *toDelete1 = Bobo.getMateriaPtr(0);
		AMateria *toDelete2 = Bobo.getMateriaPtr(1);
		std::cout << "Printing materials of BOBO before droping" << std::endl;
		Bobo.listAllMaterials();
		Bobo.unequip(0);
		Bobo.unequip(1);
		std::cout << "Printing materials of BOBO2" << std::endl;
		Bobo2.listAllMaterials();
		std::cout << std::endl;
		std::cout << "Printing materials of BOBO after droping" << std::endl;
		Bobo.listAllMaterials();
		delete toDelete1;
		delete toDelete2;
	}
	printEnd();
}

//test forr deep copy = operator
void test7(void) 
{
	prinTest("7");
	{
		Character first("Plameni jazavac");
		Character second("Ugojenko");

		first.equip(new Ice());
		first.equip(new Ice());
		first.equip(new Cure());

		second.equip(new Ice());
		second.equip(new Cure());

		first = second;

		first.listAllMaterials();
	}
	printEnd();

}

//subject main
//THERE IS PROBLEM WITH EQIP it should delete if there is no slot
//corrected after felix evaluation, if there is no slot delete *m
void test8(void)
{
	prinTest("8");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);
		

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	printEnd();
}

//trying to learn more than 4
void test9(void)
{
	prinTest("9");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("fire");

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	printEnd();

}


void test10(void)
{
	Character filip;

	filip.equip(new Ice());
	AMateria* toDelete;
	toDelete = filip.getMateriaPtr(0);
	filip.unequip(0);
	filip.equip(new Cure());
	delete toDelete;
	toDelete = filip.getMateriaPtr(0);
	filip.unequip(0);
	delete toDelete;
}

int main()
{
	// AMateria *ptr = NULL;
	// test3(&ptr);
	// delete ptr;
	// test4();
	// test5();
	// test6();
	// test7();
	 test8();
	// test9();
	//test10();
	return (0);
}
