#include "ICharacter.hpp"
#include "Ice/Ice.hpp"
#include <iostream>

int main()
{
	AMateria *ptr;
	Ice led;

	ptr = led.clone();
	std::cout << ptr->getType() << std::endl;
	delete ptr;
	return (0);
}
