#include "Point.hpp"
#include "Fixed.hpp"


Point::Point() : x(0), y(0)
{
}

Point::Point(const Fixed num1, const Fixed num2) : x(num1), y(num2)
{
}

Point::Point(const Point& source): x(source.x), y(source.y)
{
}

Point::~Point()
{
}

Point& Point::operator=(const Point& source)
{
	const_cast<Fixed&>(x) = source.x;
	const_cast<Fixed&>(y) = source.y;
	return (*this);
}

void Point::printCoordinates(void) const
{
	std::cout << "X is " << x.toFloat() <<", Y is " << y.toFloat() << std::endl;
}

float Point::getX() const
{
	const float result = x.toFloat();
	return (result);
}

float Point::getY() const
{
	const float result = y.toFloat();
	return (result);
}
