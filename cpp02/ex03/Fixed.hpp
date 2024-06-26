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

		//comparison opearators 6
		bool operator>(const Fixed& num2) const;
		bool operator<(const Fixed& num2) const;
		bool operator>=(const Fixed& num2) const;
		bool operator<=(const Fixed& num2) const;
		bool operator==(const Fixed& num2) const;
		bool operator!=(const Fixed& num2) const;


		//arithmetic operators 4
		Fixed operator+(const Fixed& num2);
		Fixed operator-(const Fixed& num2);
		Fixed operator*(const Fixed& num2);
		Fixed operator/(const Fixed& num2);

		//4increment and decrement operators
		Fixed operator++(int);
		Fixed& operator++();
		Fixed operator--(int);
		Fixed& operator--();

		//static functions
		static Fixed& min(Fixed& num1, Fixed& num2);
		const static Fixed& min(const Fixed& num1, const Fixed& num2);
		static Fixed& max(Fixed &num1, Fixed& num2);
		const static Fixed& max(const Fixed& num1, const Fixed& num2);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};
std::ostream& operator << (std::ostream& out, const Fixed& myObject);

#endif
