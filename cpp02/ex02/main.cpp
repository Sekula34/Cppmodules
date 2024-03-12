#include "Fixed.hpp"

int main()
{
	Fixed a(10);
	Fixed b(8);

	Fixed c;
	a+(b);

	std::cout <<(a-b).toFloat() << std::endl;
	return 0;
}
