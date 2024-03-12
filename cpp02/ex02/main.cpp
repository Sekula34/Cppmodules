#include "Fixed.hpp"

int main()
{
	Fixed a(-1.0f);
	Fixed b(-1.1f);

	if(a != b)
		std::cout << "a is not equal  than b" << std::endl;
	else
		std::cout << "a is  " << std::endl;
	return 0;
}
