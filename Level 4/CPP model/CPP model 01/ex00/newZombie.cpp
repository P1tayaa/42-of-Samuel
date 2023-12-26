#include "Zombie.hpp"


Zombie* newZombie( std::string name)
{
	Zombie	*the_zomb;

	the_zomb = new Zombie(name);
	return(the_zomb);
}
