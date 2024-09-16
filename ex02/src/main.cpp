#include <fixed.hpp>


int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "\n------------------" << std::endl;
	std::cout << "1: " << a << std::endl;
	std::cout << "\n------------------" << std::endl;
	std::cout << "2: " << ++a << std::endl;
	std::cout << "\n------------------" << std::endl;
	std::cout << "3: " << b << std::endl;
	std::cout << "\n------------------" << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}