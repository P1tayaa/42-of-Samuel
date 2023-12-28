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
	bool	operator<(const Fixed &other);
	bool	operator<=(const Fixed &other);
	bool	operator>(const Fixed &other);
	bool	operator>=(const Fixed &other);
	bool	operator==(const Fixed &other);
	bool	operator!=(const Fixed &other);
	Fixed&	operator+(const Fixed &other);
	Fixed&	operator-(const Fixed &other);
	Fixed&	operator*(const Fixed &other);
	Fixed&	operator/(const Fixed &other);
	Fixed&	operator++();
	Fixed&	operator++(int);
	Fixed&	operator--();
	Fixed&	operator--(int);
	int		toInt() const;
	float       toFloat() const;
	static Fixed&	min(Fixed& a, Fixed& b);
	const static Fixed&	min(const Fixed& a, const  Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	const static Fixed&	max(const Fixed& a, const  Fixed& b);


	private:
	int fixed_value;
	const int fixed_value_size = 8;
};

std::ostream    &operator<<(std::ostream& os, const Fixed &input);

# endif