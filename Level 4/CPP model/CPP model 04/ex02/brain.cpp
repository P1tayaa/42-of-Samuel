#include "brain.hpp"

Brain::Brain()
{
    std::cout << "constructed a Brain\n";
}

Brain::Brain(const Brain &other)
{
    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i];
    }
    std::cout << "copy const brain called\n";
}

Brain &Brain::operator=(const Brain &other)
{
    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i];
    }
    std::cout << "assigned brain called\n";
    return (*this);
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
