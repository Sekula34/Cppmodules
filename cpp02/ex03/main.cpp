#include "Fixed.hpp"
#include "Point.hpp"


bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Fixed x1(0);
	Fixed y1(0);
	Fixed x2(10);
	Fixed y2(0);
	Fixed x3(20);
	Fixed y3(0);

	Fixed x4(1.9f);
	Fixed y4(-4.8f);

	Point A(x1, y1);
	Point B(x2, y2);
	Point C(x3, y3);
	Point point(x4, y4);

	if(bsp(A, B, C, point) == true)
		std::cout << "inside" << std::endl;
	else 
		std::cout << "outside" << std::endl;
	return (0);
}
