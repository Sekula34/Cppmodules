
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

//test for showing that dog brain works;
//proves that copy is depp. Idea will be changed in second if it wasnt
void test1()
{
	Dog ker;

	ker.setIdea("Imam ideju", 1);
	ker.setIdea("I could bark at next person", 50);
	std::cout << "ALL IDEAS FROM FIRST DOG" << std::endl;

	Dog seconddog(ker);
	ker.setIdea("I will not bark", 50);
	ker.tellEverything();
	std::cout << "ALL IDEAS FROM DEEP COPY DOG" << std::endl;
	seconddog.tellEverything();
	
}

//same as test1 except it is cat this time
void test2()
{

	Cat ker;

	ker.setIdea("Imam ideju", 1);
	ker.setIdea("I need foood", 10);
	std::cout << "ALL IDEAS FROM FIRST CAT" << std::endl;

	Cat seconddog(ker);
	ker.setIdea("I will probably hurt you", 10);
	ker.tellEverything();
	std::cout << "ALL IDEAS FROM DEEP COPY CAT" << std::endl;
	seconddog.tellEverything();
}

void subjectTest()
{
	Animal* animal[10];

	for(int i = 0; i < 10; i++)
	{
		if(i < 5)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	for(int i = 0; i < 10; i++)
	{
		delete animal[i];
	}
}

void test3()
{
	Brain firstBrain;
}

int main()
{
	test1();
	test2();
	subjectTest();
	test3();
	return 0;
}
