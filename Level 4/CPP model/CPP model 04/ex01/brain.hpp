#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{

public:
    Brain();
    Brain(const Brain &other);
    Brain & operator = (const Brain &other);
    ~Brain();
    std::string get_idea(int x);
    void    set_idea(int x, std::string new_idea);
    std::string ideas[100];
};



# endif
