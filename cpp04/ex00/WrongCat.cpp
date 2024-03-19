#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	std::cout << "Called WrongCat constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& source)
{
	std::cout << "Called WrongCat copy constructor" << std::endl;
	this->wrongType = source.wrongType;
}

WrongCat& WrongCat::operator=(const WrongCat& source)
{
	std::cout << "Called WrongCat = operator" << std::endl;
	this->wrongType = source.wrongType;
	return(*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "Called WrongCat destructor" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout <<"WrongCat sound" << std::endl;
}
