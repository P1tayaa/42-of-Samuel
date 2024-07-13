# pragma once

# include <iostream>
#include <algorithm>

template<typename T>
bool easyfind(T container, int search) { 
    if (std::find(container.begin(), container.end(), search) == container.end())
        return false;
    return true;
}