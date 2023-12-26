#include "Zombie.hpp"


void randomChump(std::string name);
Zombie* newZombie( std::string name);

int main()
{
	Zombie	*Bob;
	Zombie	*Thiery;
	Zombie	*Lora;

	randomChump("random Bob");
	randomChump("random Thiery");
	randomChump("random Lora");
	Bob = newZombie("Bob");
	Thiery = newZombie("Thiery");
	Lora = newZombie("Lora");

	Bob->announce();
	Thiery->announce();
	Lora->announce();

	delete Lora;
	delete Thiery;
	delete Bob;
	return (0);
}