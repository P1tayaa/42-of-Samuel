#ifndef FIXED_HPP
# define FIXED_HPP
// #include <string>

#include <iostream>
#include <cmath>

class Fixed
{
	public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed& operator=(const Fixed &other);
	int		toInt() const;
	float       toFloat() const;

	private:
	int fixed_value;
	const int fixed_value_size = 8;
};

std::ostream    &operator<<(std::ostream& os, const Fixed &input);

# endif