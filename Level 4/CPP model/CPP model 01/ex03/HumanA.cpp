#include "HumanA.hpp"

void    HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << (this->type).getType() << std::endl;
}

void    HumanA::setWeapon(Weapon main_weapon)
{
    this->type = main_weapon;
}