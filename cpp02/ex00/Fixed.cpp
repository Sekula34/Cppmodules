#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	_fixedPointNumValue = 0;
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

const int Fixed::_numberOfFractionalBits = 8;
