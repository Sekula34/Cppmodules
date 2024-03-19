#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : wrongType("WRONG ANIMAL")
{
	std::cout << "Called WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& source)
{
	std::cout << "Called WrongAnimal copy constructor" << std::endl;
	wrongType = source.wrongType;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& source)
{
	std::cout << "Called WrongAnimal = operator" << std::endl;
	this->wrongType = source.wrongType;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Called WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout <<"WRONG ANIMAL SOUND" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (wrongType);
}

