#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	type = "Cat";
	std::cout << "Called Cat default constructor" << std::endl;
	std::cout << "My type is " << type << std::endl;
}

Cat::Cat(const Cat& source)
{
	std::cout << "Called Cat copy constructor" << std::endl;
	type = source.type;
}

Cat&::Cat::operator=(const Cat &source)
{
	std::cout << "Called Cat = operator" << std::endl;
	this->type = source.type;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Called Cat destructor" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "meow meow" << std::endl;
}
