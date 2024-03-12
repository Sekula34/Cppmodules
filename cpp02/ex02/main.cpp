#include "Fixed.hpp"

int main()
{
	Fixed a(0.5f);
	Fixed b(0.5f);

	Fixed c;
	a+(b);

	std::cout <<(a*b).toFloat() << std::endl;
	return 0;
}
