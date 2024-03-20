#include <iostream>
#include "Dog.hpp"
#include "Animal.hpp"
#include "Cat.hpp"

int main()
{

	const Animal* j = new Dog();
	const Animal* i = new Cat();


	std::cout << " I am prinint j type " << i->getType() << std::endl;
	delete j;
	delete i;

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
	// return 0;
}
