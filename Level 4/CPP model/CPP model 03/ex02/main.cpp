#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap Bob("Bob");
    ScavTrap Michel("Michel");
    FragTrap Toby("Toby");

    Bob.attack("Michel");
    Michel.takeDamage(0);
    Michel.beRepaired(2);
	Michel.attack("Toby");
	Toby.takeDamage(20);
    return (0);
}