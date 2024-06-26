#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Fixed{
	private:
		int					_value;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		~Fixed();
};

#endif