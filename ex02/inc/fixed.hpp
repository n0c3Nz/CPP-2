#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int					_value;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int raw);//It converts it to the corresponding fixed-point value
		Fixed(const float raw);//It converts it to the corresponding fixed-point value
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);//✅
		Fixed operator+(const Fixed &other);//✅
		Fixed operator-(const Fixed &other);//✅
		Fixed operator*(const Fixed &other);//✅
		Fixed operator/(const Fixed &other);//✅
		bool	operator>(const Fixed &other);//✅
		bool	operator<(const Fixed &other);//✅
		bool	operator>=(const Fixed &other);//✅
		bool	operator<=(const Fixed &other);//✅
		bool	operator==(const Fixed &other);//✅
		bool	operator!=(const Fixed &other);//✅
		Fixed &operator++(void);//prefix
		Fixed &operator--(void);//prefix
		Fixed operator++(int);//postfix
		Fixed operator--(int);//postfix
		float			toFloat( void ) const;//Converts the fixed-point value to a floating-point value.
		int				toInt( void ) const;//Converts the fixed-point value to an integer value.
		int				getRawBits( void ) const;
		void			setRawBits( int const raw );
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
		~Fixed();
};

	std::ostream	&operator<<(std::ostream &out, const Fixed &f);

#endif