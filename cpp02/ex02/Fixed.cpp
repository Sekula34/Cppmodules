#include "Fixed.hpp"
# include <cmath>

float Fixed::_intDecimaltoFloat(int decimalInt) const
{
	float factor = 0.00390625; //2 to the power of -8
	float result = 0;
	
	for (int i = 0; i < _numberOfFractionalBits; i++)
	{
		if((decimalInt & 0x1) == true)
		{
			result += factor;
		}
		factor *= 2;
		decimalInt = decimalInt >> 1;
	}
	return (result);
}

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPointNumValue = 0;
}

// A constructor that takes a constant integer as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value is
// initialized to 8 like in exercise 00
Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	int absValue;
	if(intValue > MAX_FIXED || intValue < MIN_FIXED)
	{
		std::cerr << "integer Value is out of range for Fixed type" << std::endl;
		throw ;
	}
	if(intValue < 0)
		absValue = intValue * (-1);
	else
		absValue = intValue;
	_fixedPointNumValue = absValue << _numberOfFractionalBits;
	if(intValue < 0)
		_fixedPointNumValue *= (-1);
}

// • A constructor that takes a constant floating-point number as a parameter.
// It converts it to the corresponding fixed-point value. The fractional bits value is
// initialized to 8 like in exercise 00
Fixed::Fixed(const float flValue)
{
	std::cout << "Float constructor called" << std::endl;
	int value;

	value = roundf(flValue * (1 << _numberOfFractionalBits));
	this->setRawBits(value);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed& source)
{
	std::cout << "Copy assigment operator called" << std::endl;
	this->_fixedPointNumValue = source._fixedPointNumValue;
	return (*this);
}

Fixed::Fixed(const Fixed& source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	int rawBits;
	rawBits = _fixedPointNumValue;
	return (rawBits);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointNumValue = raw;
}

// A member function float toFloat( void ) const;
// that converts the fixed-point value to a floating-point value.
float Fixed::toFloat(void) const
{
	int absFixPointVal;
	int negativeSign = 1;
	int leftPart;
	int decimalPart;
	float result;

	if(_fixedPointNumValue < 0)
	{
		negativeSign = -1;
		absFixPointVal = _fixedPointNumValue * (-1);
	}
	else 
		absFixPointVal = _fixedPointNumValue;
	leftPart = absFixPointVal >> 8 ;
	decimalPart = absFixPointVal & 0xFF;
 	result = (float(leftPart) + _intDecimaltoFloat(decimalPart)) * (negativeSign);
	return (result);
}

// • A member function int toInt( void ) const;
// that converts the fixed-point value to an integer va
int Fixed::toInt(void) const 
{
	int result;
	
	result = _fixedPointNumValue >> _numberOfFractionalBits;
	return(result);
}

std::ostream& operator<< (std::ostream& out, const Fixed &myObject) 
{
	out << myObject.toFloat();
	return(out);
}

bool Fixed::operator> (const Fixed& num2) const
{
	if(this->_fixedPointNumValue > num2._fixedPointNumValue)
		return (true);
	else
		return(false);
}

bool Fixed::operator< (const Fixed& num2) const
{
	if(this->_fixedPointNumValue < num2._fixedPointNumValue)
		return (true);
	else
		return (false);
}

bool Fixed::operator>=(const Fixed& num2) const
{
	if(this->_fixedPointNumValue >= num2._fixedPointNumValue)
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(const Fixed& num2) const
{
	if(this->_fixedPointNumValue <= num2._fixedPointNumValue)
		return (true);
	else
		return (false);
}

bool Fixed::operator==(const Fixed& num2) const
{
	if(this->_fixedPointNumValue == num2._fixedPointNumValue)
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(const Fixed& num2) const
{
	if(this->_fixedPointNumValue != num2._fixedPointNumValue)
		return (true);
	else
		return(false);
}

Fixed Fixed::operator+(const Fixed& num2)
{
	Fixed sum;

	sum._fixedPointNumValue = _fixedPointNumValue + num2._fixedPointNumValue;
	return(sum);
}

Fixed Fixed::operator-(const Fixed& num2)
{
	Fixed difference;
	difference._fixedPointNumValue = _fixedPointNumValue - num2._fixedPointNumValue;
	return (difference);
}

Fixed Fixed::operator*(const Fixed& num2)
{
	float result;
	result = this->toFloat() * num2.toFloat();
	Fixed multiple(result);
	return (multiple);
}

Fixed Fixed::operator/(const Fixed& num2)
{
	if(num2._fixedPointNumValue == 0)
	{
		std::cerr << "Dividing by zero is undefined behaviour" << std::endl;
		throw ;
	}
	float result;
	result = this->toFloat() / num2.toFloat();
	Fixed quotient(result);
	return(quotient);
}

Fixed Fixed::operator++(int)
{
	Fixed postIncrement(*this);
	_fixedPointNumValue++;
	return (postIncrement);
}

Fixed& Fixed::operator++()
{
	this->_fixedPointNumValue ++;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed postDecrement(*this);
	_fixedPointNumValue--;
	return(postDecrement);
}

Fixed& Fixed::operator--()
{
	this->_fixedPointNumValue--;
	return(*this);
}

Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	if(num1 < num2)
		return(num1);
	else
		return(num2);
}

const Fixed& Fixed::min(const Fixed& num1, const Fixed &num2)
{
	if(num1 <= num2)
		return (num1);
	return (num2);
}

Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	if(num1 >= num2)
		return (num1);
	else
	 	return (num2);
}

const Fixed& Fixed::max(const Fixed& num1, const Fixed& num2)
{
	if(num1 >= num2)
		return num1;
	else
		return (num2);
}
const int Fixed::_numberOfFractionalBits = 8;

