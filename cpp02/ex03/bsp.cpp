#include "Point.hpp"

float getTriangleArea(Point a, Point b, Point c)
{
	float area;
	float x1, x2, x3, y1, y2, y3;
	x1 = a.getX();
	y1 = a.getY();
	x2 = b.getX();
	y2 = b.getY();
	x3 = c.getX();
	y3 = c.getY();

	float absRes = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
	if(absRes < 0)
		absRes *= (-1);
	area = 0.5 * absRes;
	return (area);
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float triangleABC;
	float trianglePAB;
	float trianglePBC;
	float trianglePAC;

	triangleABC = getTriangleArea(a, b, c);
	trianglePAB = getTriangleArea(point, a, b);
	trianglePBC = getTriangleArea(point, b, c);
	trianglePAC = getTriangleArea(point, a, c);
	if(triangleABC == 0 || trianglePAB == 0 || trianglePBC == 0 || trianglePAC == 0)
		return (false);
	if(triangleABC == trianglePAB + trianglePBC + trianglePAC)
		return (true);
	return (false);
}
