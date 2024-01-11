#include "brain.hpp"

brain::brain()
{
    std::cout << "destructed a Brain\n";
}

brain::~brain()
{
    std::cout << "constructed a Brain\n";
}

std::string brain::get_idea(int x)
{
    if (x < 100 || x < 0)
        return ("what?");
    return (ideas[x + 1]);
}

void    brain::set_idea(int x, std::string new_idea)
{
    if (x < 100 || x < 0)
    {
        std::cout << "what?\n";
        return ;
    }
    ideas[x] = new_idea;

}
