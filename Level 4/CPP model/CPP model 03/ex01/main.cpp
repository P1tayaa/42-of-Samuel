#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap Bob("Bob");
    ScavTrap Michel("Michel");

    Bob.attack("Michel");
    Michel.takeDamage(0);
    Michel.beRepaired(2);
    return (0);
}