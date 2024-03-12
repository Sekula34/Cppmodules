#include "Fixed.hpp"

int main()
{
	Fixed a(100);
	Fixed b(1);

	Fixed c;
	
	
	std::cout <<(a).toFloat() << std::endl;
	std::cout <<a.toFloat() << std::endl;
	return 0;
}
