#pragma once

// # include "Array.tpp"

// Construction with no parameter: Creates an empty array.
// • Construction with an unsigned int n as a parameter: Creates an array of n elements
// initialized by default.
// Tip: Try to compile int * a = new int(); then display *a.
// • Construction by copy and assignment operator. In both cases, modifying either the
// original array or its copy after copying musn’t affect the other array.
// • You MUST use the operator new[] to allocate memory. Preventive allocation (al-
// locating memory in advance) is forbidden. Your program must never access non-
// allocated memory.
// • Elements can be accessed through the subscript operator: [ ].
// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
// • A member function size() that returns the number of elements in the array. This
// member function takes no parameter and musn’t modify the current instance.

// class	InvalidIndexException;

# include <iostream>

class	InvalidIndexException : public std::exception
{
public:
    virtual const char	*what() const throw();
};

template <typename T>
class Array
{
private:
    unsigned int _size;
    T   *_first_array;
    void    init_array();
    InvalidIndexException _error;
public:
    Array();
    Array(unsigned int size);
    Array(Array &dup);
    Array &operator=(const Array& other);
    T& operator[](unsigned int i) const;
    unsigned int size(void);
    ~Array();
};


const char	*InvalidIndexException::what() const throw(){
    return ("ERROR: INVALIDE INDEX\n");
}


template <typename T>
Array<T>::Array() {_first_array = nullptr; _size = 0;}

template <typename T>
Array<T>::Array(unsigned int size) {_size = size; init_array();}

template <typename T>
Array<T>::Array(Array &dup) {
    _size = dup.size();
    init_array();
    for (uint i = 0; i < _size; i++) {
        this[i] = dup[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& other) {
    delete []_first_array;
    _size = other.size();
    init_array();
    for (uint i = 0; i < _size; i++) {
        this[i] = other[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i) const {
    if (i < 0 || i >= _size) {
        std::cout << "Range is 0 " << _size << " and " << i << " is not in it\n";
        throw _error;
    }
    return (_first_array[i]);
}

template <typename T>
unsigned int Array<T>::size(void) {
    return (_size);
}

template <typename T>
Array<T>::~Array() {delete[] _first_array;}

template <typename T>
void Array<T>::init_array() {
    _first_array = new T[_size];
}

