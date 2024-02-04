#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "New zombie exist\n";
}

Zombie::Zombie() 
{
    std::cout << "Murcellelly killed dear " << this->name << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Murcellelly killed dear " << this->name << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": Brrrrrraaaaainnnnn" << std::endl;
}