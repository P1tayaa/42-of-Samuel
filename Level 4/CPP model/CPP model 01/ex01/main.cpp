#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name);

int main(void)
{
	size_t		Horde_size = 5;
	Zombie *zombie_Horde = zombieHorde(Horde_size, "Boby");

	for (size_t i = 0; i < Horde_size; i++)
	{
		std::cout << "new zombie talk" << i << std::endl;
		zombie_Horde[i].announce();
	}
	delete[] zombie_Horde;
	return (0);
}