#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;
    std::cout << name << " FragTrap constructor called\n";
}

FragTrap::~FragTrap()
{
    std::cout << this->name << " FragTrap destructor called\n";
}

void FragTrap::highFivesGuys(void)
{
    if (energy_point <= 0)
            return ;
    this->energy_point--;
    std::cout << this->name << " is requesting a high five\n";
}
