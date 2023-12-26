#include "Zombie.hpp"

Zombie::~Zombie()
{
    std::cout << "Murcellelly killed dear " << this->name << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->name << ": Brrrrrraaaaainnnnn" << std::endl;
}