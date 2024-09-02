# pragma once

# include <iostream>
# include <algorithm>
# include <list>

class SpanSizeExecess : public std::exception {
    public:
    virtual const char* what() const throw();
};


class Span
{
private:
    std::list<int> storage;
    unsigned int size;
    unsigned int max_size;
public:
    SpanSizeExecess error;
    Span(unsigned int size);
    Span(Span &dup);
    Span &operator=(Span &dup);
    void addNumber(int num);
    void addNumber(std::list<int>::iterator begin, std::list<int>::iterator end);
    int shortestSpan();
    int longestSpan();
    ~Span();
};

