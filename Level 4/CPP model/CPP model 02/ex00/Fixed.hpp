#include <iostream>
// #include <string>

class Fixed
{
    public:
    Fixed();
    Fixed(int const raw);
    Fixed(Fixed& other);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    Fixed& operator=(const Fixed &other);

    private:
    int fixed_value;
    const int fixed_value_size = 8;
};
