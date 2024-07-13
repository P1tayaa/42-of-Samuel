# pragma once

# include <iostream>
# include <algorithm>
# include <vector>

class Span
{
private:
    std::vector<int> *storage;
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

Span::Span(unsigned int size) : size(0), max_size(size) { storage = new std::vector<int>;}

Span::Span(Span &dup) {
    storage = dup.storage;
    max_size = dup.max_size;
    size = dup.size;
}

Span &Span::operator=(Span &dup) {
    storage = dup.storage;
    max_size = dup.max_size;
    size = dup.size;
    return *this;
}

void Span::addNumber(int num) {
    (*storage).push_back(num);
    std::sort((*storage).begin(), (*storage).end());
    size++;
}

int Span::shortestSpan() {
    int shortestspan = std::abs((*storage)[0] - (*storage)[1]);
    int tempspan;
    for (size_t i = 1; i < (*storage).size() + 1; i++)
    {
        tempspan = std::abs((*storage)[i] - (*storage)[i + 1]);
        if (tempspan < shortestspan)
            shortestspan = tempspan;
    }
    return shortestspan;
}

int Span::longestSpan() {
    int shortestspan = std::abs((*storage)[0] - (*storage)[1]);
    int tempspan;
    for (size_t i = 1; i < storage->size() + 1; i++)
    {
        tempspan = std::abs((*storage)[i] - (*storage)[i + 1]);
        if (tempspan > shortestspan)
            shortestspan = tempspan;
    }
    return shortestspan;
}

Span::~Span()
{
    delete storage;
}
