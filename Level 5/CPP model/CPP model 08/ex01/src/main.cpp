# include "../include/Span.hpp"

int main(void) {
    Span test(5);

    for (size_t i = 0; i < 5; i++)
    {
        test.addNumber(i);
    }
    std::cout << test.longestSpan() << " is long and short is " << test.shortestSpan() << std::endl;
}