#include "Fixed.hpp"

int main()
{
	Fixed a(42.42f);
	std::cout << a.getRawBits() << std::endl;
	std::cout << a.toFloat() << std::endl;
	std::cout << a.toInt() << std::endl;
	return (0);
}
