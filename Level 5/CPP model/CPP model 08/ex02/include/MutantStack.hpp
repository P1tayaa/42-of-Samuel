# pragma once
#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T>>
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() {return this->c.begin();}
    iterator end() {return this->c.end();}
};
