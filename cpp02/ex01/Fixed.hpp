#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# define MAX_FIXED 8388607
# define MIN_FIXED -8388608

class Fixed
{
	private:
		int _fixedPointNumValue;
		static const int _numberOfFractionalBits;
		float _intDecimaltoFloat(const int decimalInt) const;
	public:
		Fixed();
		Fixed(const int intValue);
		Fixed(const float flValue);
		Fixed(const Fixed &source);
		Fixed& operator= (const Fixed &source);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};
std::ostream& operator << (std::ostream& out, const Fixed& myObject);

#endif
