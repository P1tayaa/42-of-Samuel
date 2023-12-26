#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie	the_zomb = Zombie(name);
	// the_zomb = Zombie(name);
	the_zomb.announce();
}