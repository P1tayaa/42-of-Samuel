# include "../include/Span.hpp"

const char *SpanSizeExecess::what() const throw(){
    return ("Span can't have more than max_size");
}

Span::Span(unsigned int size) : size(0), max_size(size) {}

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
    if (size < max_size) {
        (storage).push_back(num);
        size++;
    } else
        throw this->error;
}

void Span::addNumber(std::list<int>::iterator begin, std::list<int>::iterator end) {
    if (size + std::distance(begin, end) > max_size)
        throw this->error;
    storage.insert(storage.end(), begin, end);
    size += std::distance(begin, end);
}


int Span::shortestSpan() {
    if (size < 2)
        throw std::out_of_range("Span::shortestSpan: list too short");
    int shortestspan = longestSpan();
    for (std::list<int>::const_iterator it = storage.begin(); it != storage.end(); it++) {
        for (std::list<int>::const_iterator it2 = storage.begin(); it2 != storage.end(); it2++) {
            if (it == it2)
                continue ;
            if (shortestspan > std::abs(*it - *it2))
                shortestspan = std::abs(*it - *it2);
        }
    }
    return shortestspan;
}

int Span::longestSpan() {
    if (size < 2)
        throw std::out_of_range("Span::longestSpan: list too short");
    return (*std::max_element(storage.begin(), storage.end()) - *std::min_element(storage.begin(), storage.end()));
}

Span::~Span() {}