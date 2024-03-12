#include "Fixed.hpp"

int main()
{
	Fixed a(1.1f);
	Fixed b(2.2f);

	Fixed c;
	a+(b);

	std::cout <<(a+b).toFloat() << std::endl;
	return 0;
}
