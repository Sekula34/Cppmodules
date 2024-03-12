#include "Fixed.hpp"

int main()
{
	Fixed a(0.5f);
	Fixed b(1);

	Fixed c;
	
	
	std::cout << Fixed::max(a, b) << std::endl;
	return 0;
}
