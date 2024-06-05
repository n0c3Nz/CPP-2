#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	private:
		int					_value;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int raw);//It converts it to the corresponding fixed-point value
		Fixed(const float raw);//It converts it to the corresponding fixed-point value
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		~Fixed();
	
		float	toFloat( void ) const;//Converts the fixed-point value to a floating-point value.
		int		toInt( void ) const;//Converts the fixed-point value to an integer value.
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

	std::ostream &operator<<(std::ostream &out, const Fixed &f);

#endif