
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

	Dog basic;
	{
	Dog tmp = basic;
	}

	Cat first;
	{
		Cat copy(first);
		Cat assign = first;
	}
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
