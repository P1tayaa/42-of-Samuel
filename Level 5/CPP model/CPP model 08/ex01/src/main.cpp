# include "../include/Span.hpp"

int main(void) {
    Span test(501);
    std::list<int> temp;
    try {
        test.addNumber(15);
        std::cout << test.longestSpan() << " is long and short is " << test.shortestSpan() << std::endl;
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < 500; i++) {
        temp.push_back(i);
        // test.addNumber(i);
    }
    test.addNumber(temp.begin(), temp.end());
    std::cout << test.longestSpan() << " is long and short is " << test.shortestSpan() << std::endl;
    Span dup(test);
    std::cout << test.longestSpan() << " is long (of dup) and short is " << test.shortestSpan() << std::endl;
    try {
        test.addNumber(15);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
