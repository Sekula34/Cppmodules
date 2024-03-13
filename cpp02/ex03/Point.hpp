#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point 
{
	private:
		const Fixed x;
		const Fixed y;

	public:
		//orthodox canonical Form
		Point();
		Point(const Point &source);
		Point& operator=(const Point &source);
		~Point();
		Point(const Fixed num1, const Fixed num2);

		//anything else useful
		void printCoordinates(void) const;
		float getX(void) const;
		float getY(void) const;
};

#endif
