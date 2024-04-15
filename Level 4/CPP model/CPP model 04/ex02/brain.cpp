#include "brain.hpp"

Brain::Brain()
{
    std::cout << "constructed a Brain\n";
}

Brain::~Brain()
{
    std::cout << "destructed a Brain\n";
}

std::string Brain::get_idea(int x)
{
    if (x > 100 || x < 0)
        return ("what?");
    return (ideas[x]);
}

void    Brain::set_idea(int x, std::string new_idea)
{
    if (x > 100 || x < 0)
    {
        std::cout << "what?\n";
        return ;
    }
    ideas[x] = new_idea;

}
