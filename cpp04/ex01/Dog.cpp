#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(void)
{
	type = "Dog";
	std::cout << "Default Dog constructor called" << std::endl;
	std::cout << "My animal type is " << type << std::endl;
	try 
	{
		brainPtr = new Brain();
	}
	catch(std::bad_alloc&)
	{
		std::cerr << "Mem allocation failed" << std::endl;
	}
}

Dog::Dog(const Dog& source)
{
	std::cout << "Called Dog copy constructor" << std::endl;
	type = source.type;
}

Dog& Dog::operator=(const Dog& source)
{
	std::cout << "Called Dog = operator" << std::endl;
	this->type = source.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Called Dog destructor" << std::endl;
	delete brainPtr;
}

void Dog::makeSound(void) const
{
	std::cout << "woof woof" << std::endl;
}
