#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap Bob("Bob");
    ScavTrap Michel("Michel");

    Bob.attack("Michel");
    Michel.takeDamage(0);
    Michel.attack("Bob");
    Bob.takeDamage(20);
    Michel.guardGate();
    Bob.beRepaired(2);
    return (0);
}