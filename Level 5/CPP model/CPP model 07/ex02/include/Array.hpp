#pragma once

# include "Array.tpp"

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

class	InvalidIndexException : public std::exception
{
public:
    virtual const char	*what() const throw();
};

template <typename T>
class Array
{
private:
    uint _size;
    T   *_first_array;
    void init_array();
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
