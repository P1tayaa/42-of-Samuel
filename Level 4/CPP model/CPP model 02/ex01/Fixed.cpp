#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->setRawBits(0);
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	this->setRawBits(other.getRawBits());
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->fixed_value);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_value = raw;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return (*this);
}

Fixed::Fixed(const int value)
{
	this->fixed_value = value << this->fixed_value_size;
}

Fixed::Fixed(const float value)
{
	int		scale_factor = 1 << this->fixed_value_size;
	float	almost_fixed = value * scale_factor;

	this->fixed_value = static_cast<int> (std::roundf(almost_fixed));
}

int		Fixed::toInt() const
{
	return (fixed_value >> 8);
}

float		Fixed::toFloat() const
{
	return (static_cast<float> (fixed_value) / (1 << fixed_value_size));
}

std::ostream    &operator<<(std::ostream& os, const Fixed &input)
{
	os << input.toFloat();
	return (os);
}
