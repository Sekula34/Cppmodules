
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

int main()
{
	test1();
	// Dog basic;
	// {
	// Dog tmp = basic;
	// }

	// Cat first;
	// {
	// 	Cat copy(first);
	// 	Cat assign = first;
	// }
	// Animal* animal[10];

	// for(int i = 0; i < 10; i++)
	// {
	// 	if(i < 5)
	// 		animal[i] = new Dog();
	// 	else
	// 		animal[i] = new Cat();
	// }
	// for(int i = 0; i < 10; i++)
	// {
	// 	delete animal[i];
	// }
	 return 0;
}
