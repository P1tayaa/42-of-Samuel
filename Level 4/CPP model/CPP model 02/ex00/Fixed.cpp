#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    this->setRawBits(0);
}

Fixed::Fixed(int const raw)
{
    std::cout << "Copy constructor called, v1\n";
    this->setRawBits(raw);
}

Fixed::Fixed(Fixed& other)
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
