#include <fixed.hpp>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	_value = other._value ? int(other._value) : 0;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other._value ? int(other._value) : 0;
	return *this;
}

Fixed Fixed::operator+(const Fixed &other) {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) {
	return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed &other) {
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed &other) {
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) {
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) {
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) {
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other) {
	return (this->toFloat() != other.toFloat());
}

Fixed &Fixed::operator++() {//prefix
	_value++;
	return *this;
}

Fixed Fixed::operator++(int) {//postfix
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--() {//prefix
	_value--;
	return *this;
}

Fixed Fixed::operator--(int) {//postfix
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return (a.toFloat() < b.toFloat() ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	return (a.toFloat() < b.toFloat() ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return (a.toFloat() > b.toFloat() ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	return (a.toFloat() > b.toFloat() ? a : b);
}

float Fixed::toFloat(void) const {
	return ((float) _value / (1 << _fractionalBits));
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called\n";
	_value = n << _fractionalBits; 
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called\n";
	_value = (int)(n * (1 << _fractionalBits));
}


Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits( int const raw ) {
	_value = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

int	Fixed::toInt(void) const {
	return (_value >> _fractionalBits);
}

std::ostream	&operator<<(std::ostream &output, const Fixed &obj) {
	output << obj.toFloat();
	return (output);
}
