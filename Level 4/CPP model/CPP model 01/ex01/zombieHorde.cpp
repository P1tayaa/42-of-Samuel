#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie*	zombie_horde = new Zombie[N];
    int			i;

	for (i = 0; i < N; i++)
    {
        zombie_horde[i] = Zombie(name);
    }
    return (zombie_horde);
}
