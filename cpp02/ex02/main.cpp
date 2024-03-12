#include "Fixed.hpp"

int main()
{
	Fixed a(-1.0f);
	Fixed b(-1);

	if(a == b)
		std::cout << "a is equal  than b" << std::endl;
	else
		std::cout << "a is not " << std::endl;
	return 0;
}
