# pragma once

# include <iostream>
# include <algorithm>
# include <list>

class Span
{
private:
    std::list<int> storage;
    unsigned int size;
    unsigned int max_size;
public:
    Span(unsigned int size);
    Span(Span &dup);
    Span &operator=(Span &dup);
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
    ~Span();
};

