#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed
{
	private:
		int _fixedPointNumValue;
		static const int _numberOfFractionalBits;
	public:
		Fixed();
		Fixed(const Fixed &source);
		Fixed& operator= (const Fixed &source);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
