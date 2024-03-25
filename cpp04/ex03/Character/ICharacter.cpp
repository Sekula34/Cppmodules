#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
	// std::cout << "Called INTERFACE Character constructor" << std::endl;
}

ICharacter::ICharacter(ICharacter &source)
{
	(void)source;
	// std::cout << "Called INTERFACE Character copy constructor" << std::endl;
}

ICharacter& ICharacter::operator= (ICharacter &source)
{
	(void) source;
	// std::cout << "Called INTERFACE Character = operator" << std::endl;
	return (*this);
}
