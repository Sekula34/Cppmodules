#include <iostream>

int main()
{
	double c = 4.52;
	int i = static_cast<int>(c);
	double d = static_cast<double>(c);
	float f = static_cast<float>(c);

	std::cout << "C is " << c << std::endl;
	std::cout << "I is " << i << std::endl;
	std::cout << "D is " << d << std::endl;
	std::cout << "F is " << f << std::endl;
}
