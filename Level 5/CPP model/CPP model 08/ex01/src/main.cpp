# include "../include/Span.hpp"

int main(void) {
    Span test(5);
    try
    {
        test.addNumber(15);
        std::cout << test.longestSpan() << " is long and short is " << test.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (size_t i = 0; i < 5; i++)
    {
        test.addNumber(i);
    }
    std::cout << test.longestSpan() << " is long and short is " << test.shortestSpan() << std::endl;
    Span dup(test);
    std::cout << test.longestSpan() << " is long (of dup) and short is " << test.shortestSpan() << std::endl;
}