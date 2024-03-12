#include "Fixed.hpp"

int main()
{
	Fixed a(-20.3f);
	Fixed b(20.2f);

	if(a >= b)
		std::cout << "a is bigger or equal  than b" << std::endl;
	else
		std::cout << "a is not bq than" << std::endl;
	return 0;
}
