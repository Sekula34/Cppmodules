#include "Fixed.hpp"

int main()
{
	Fixed a(20.1f);
	Fixed b(20);

	if(a > b)
		std::cout << "a is bigger than b" << std::endl;
	else
		std::cout << "a is not bigger than" << std::endl;
	return 0;
}
