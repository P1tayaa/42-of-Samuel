# pragma once

# include <iostream>
#include <algorithm>

template<typename T>
bool easyfind(T &container, int search, typename T::iterator &t) {
    typename T::iterator temp_t = std::find(container.begin(), container.end(), search);  
    if (t == container.end()){
        return false;      
    }
    t = temp_t;
    return true;
}