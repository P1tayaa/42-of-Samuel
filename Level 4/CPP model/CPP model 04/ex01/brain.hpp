#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class brain
{

public:
    brain();
    ~brain();
    std::string get_idea(int x);
    void    set_idea(int x, std::string new_idea);

private:
    std::string ideas[100];
};



# endif
