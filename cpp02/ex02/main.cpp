#include "Fixed.hpp"

int main()
{
	Fixed a(20.1f);
	Fixed b(20.2f);

	if(a < b)
		std::cout << "a is smaller  than b" << std::endl;
	else
		std::cout << "a is not smaller than" << std::endl;
	return 0;
}
