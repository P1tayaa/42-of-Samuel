#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)  : ClapTrap(name)
{
    this->hit_point = 100;
    this->energy_point = 50;
    this->attack_damage = 20;
    std::cout << name << " ScavTrap constructor called\n";
}

ScavTrap::~ScavTrap()
{
    std::cout << this->name << " ScavTrap destructor called\n";
}

void ScavTrap::guardGate()
{
    if (energy_point <= 0)
            return ;
    this->energy_point--;
    std::cout << this->name << " uses his quardGate abillity\n";
}
