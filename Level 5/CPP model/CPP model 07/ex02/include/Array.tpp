

# include "Array.hpp"

template <typename T>
Array<T>::Array() {_first_array = nullptr; _size = 0;}

template <typename T>
Array<T>::Array(unsigned int size) {_size = size; _first_array = init_array();}

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
    T* local = sizeof(T) * i + _first_array;
    return (*local);
}

template <typename T>
unsigned int Array<T>::size(void) {
    return (_size);
}

template <typename T>
Array<T>::~Array() {delete[] _first_array;}

const char	*InvalidIndexException::what() const throw(){
    return ("ERROR: INVALIDE INDEX\n");
}