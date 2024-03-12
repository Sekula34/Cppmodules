#include "Fixed.hpp"

int main()
{
	Fixed a(100);
	Fixed b(1);

	Fixed c;
	a+(b);

	std::cout <<(a/b).toFloat() << std::endl;
	return 0;
}
