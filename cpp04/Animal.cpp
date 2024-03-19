#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : type("Animal")
{
    std::cout << "Called Animal Default constructor" <<std::endl;
    std::cout << "Animal type is "<< type << std::endl;
}

Animal::~Animal(void)
{
    std::cout << "Called Animal destructor"<<std::endl;
}

Animal::Animal(const Animal& source)
{
    std::cout << "Called Animal copy constructor" << std::endl;
    this->type = source.type;
}

Animal& Animal::operator=(const Animal& source)
{
    std::cout << "Called Animal = operator"<< std::endl;
    this->type = source.type;
    return (*this);
}

void Animal::makeSound(void)
{
    std::cout << "Animal is making some sound" << std::endl;
}
