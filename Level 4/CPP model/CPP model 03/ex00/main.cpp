#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Bob("Bob");
    ClapTrap Michel("Michel");

    Bob.attack("Michel");
    Michel.takeDamage(0);
    Michel.beRepaired(2);
    return (0);
}