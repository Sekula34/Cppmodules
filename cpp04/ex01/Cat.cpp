#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>
#include <new>

Cat::Cat(void)
{
	type = "Cat";
	std::cout << "Called Cat default constructor" << std::endl;
	std::cout << "My type is " << type << std::endl;
	try 
	{
		brainPtr = new Brain();
	}
	catch(std::bad_alloc&)
	{
		std::cerr << "Mem allocation failed" << std::endl;
	}
}

Cat::Cat(const Cat& source)
{
	std::cout << "Called Cat copy constructor" << std::endl;
	type = source.type;
	try 
	{
		brainPtr = new Brain();
	}
	catch (std::bad_alloc&)
	{
		std::cerr << "Mem allocation failed" << std::endl;
	}
	*brainPtr = *(source.brainPtr);
}

Cat&::Cat::operator=(const Cat &source)
{
	std::cout << "Called Cat = operator" << std::endl;
	this->type = source.type;
	try 
	{
		brainPtr = new Brain();
	}
	catch (std::bad_alloc&)
	{
		std::cerr <<"Mem allocation failed" << std::endl;
	}
	*(this->brainPtr) = *(source.brainPtr);
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Called Cat destructor" << std::endl;
	delete brainPtr;
}

void Cat::makeSound(void) const
{
	std::cout << "meow meow" << std::endl;
}

void Cat::tellEverything(void) const
{
	this->brainPtr->listIdeas();
}

void Cat::setIdea(std::string idea, int index)
{
	this->brainPtr->setidea(idea, index);
}
