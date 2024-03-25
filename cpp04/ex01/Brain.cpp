#include "Brain.hpp"
#include <string>
#include <iostream>
#include <sstream>

Brain::Brain(void)
{
	std::cout << "Called Brain constructor" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::stringstream strI;
		strI << i;
		ideas[i] = "Idea number " + strI.str();
	}
}

Brain::Brain(const Brain& source)
{
	std::cout << "Called Brain copy constructor" << std::endl;
	for(int i = 0; i < 100; i++)
	{
		ideas[i] = source.ideas[i];
	}
}

Brain& Brain::operator= (const Brain &source)
{
	for(int i = 0; i < 100; i++)
	{
		this->ideas[i] = source.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Called Brain destructor " <<std::endl;
}

void Brain::listIdeas(void)
{
	for(int i = 0; i < 100; i++)
	{
		std::cout << ideas[i] << std::endl;
	}
}

void Brain::setidea(std::string idea, int index)
{
	if(index > 99 || index < 0)
	{
		std::cerr << "Index of idea is out of range "  << std::endl;
	}
	if(idea.empty() == true)
		idea = "<no idea>";
	ideas[index] = idea;
}
