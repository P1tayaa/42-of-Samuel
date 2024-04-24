#include <iostream>
#include "Fixed.hpp"

// int main(void)
// {
// 	Fixed a;
// 	Fixed const b(10);
// 	Fixed const c(42.42f);
// 	Fixed const d(b);
// 	a = Fixed(1234.4321f);
	
// 	return 0;
// }


#include <iostream>
#include "Fixed.hpp"  // Adjust the include path as needed

void testComparisonOperators() {
    Fixed a(10);
    Fixed b(20);
    std::cout << "Testing Comparison Operators:" << std::endl;

    // Test greater than
    std::cout << "10 > 20: " << (a > b ? "True" : "False") << ", Expected: False" << std::endl;

    // Test less than
    std::cout << "10 < 20: " << (a < b ? "True" : "False") << ", Expected: True" << std::endl;

    // Continue with >=, <=, ==, !=
}

void testArithmeticOperators() {
    Fixed a(10);
    Fixed b(3);
    std::cout << "Testing Arithmetic Operators:" << std::endl;

    // Test addition
    std::cout << "10 + 3: " << (a + b).toFloat() << ", Expected: 13" << std::endl;

    // Test subtraction, multiplication, division
}

void testIncrementDecrement() {
    Fixed a(1.5f);
    std::cout << "Testing Increment/Decrement Operators:" << std::endl;

    // Pre-increment
    ++a;
    std::cout << "++a: " << a.toFloat() << ", Expected: 2.5" << std::endl;

    // Post-increment, pre-decrement, post-decrement
}

void testStaticMethods() {
    Fixed a(10);
    Fixed b(20);
    std::cout << "Testing Static Methods:" << std::endl;

    // Test min
    std::cout << "min(10, 20): " << Fixed::min(a, b).toFloat() << ", Expected: 10" << std::endl;

    // Test max
    std::cout << "max(10, 20): " << Fixed::max(a, b).toFloat() << ", Expected: 20" << std::endl;
}

int main() {
    std::cout << "Starting Tests for Fixed Class:" << std::endl;

    testComparisonOperators();
    testArithmeticOperators();
    testIncrementDecrement();
    testStaticMethods();

    std::cout << "Tests Completed." << std::endl;
    return 0;
}
