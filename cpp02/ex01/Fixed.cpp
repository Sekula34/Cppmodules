#include "Fixed.hpp"

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
	this->_fixedPointNumValue = source.getRawBits();
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

float Fixed::toFloat(void) const
{
	int absFixPointVal;
	bool negativeSign = false;
	int leftPart;
	int decimalPart;
	float result;
	if(_fixedPointNumValue < 0)
	{
		negativeSign = true;
		absFixPointVal = _fixedPointNumValue * (-1);
	}
	else 
		absFixPointVal = _fixedPointNumValue;
	leftPart = absFixPointVal >> 8 ;
	decimalPart = absFixPointVal & 0xFF;

 	result = float(leftPart) + _intDecimaltoFloat(decimalPart);
	std::cout << "decimal part ist  "<< _intDecimaltoFloat(decimalPart) << std::endl;
	return (0);
	
}

float Fixed::_intDecimaltoFloat(int decimalInt) const
{
	double factor = 0.00390625; //2 to the power of -8
	float result = 0;
	for (int i = 0; i < 8; i++)
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
const int Fixed::_numberOfFractionalBits = 8;

