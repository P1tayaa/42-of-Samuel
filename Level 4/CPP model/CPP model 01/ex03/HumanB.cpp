#include "HumanB.hpp"

void    HumanB::attack(void)
{
    std::cout << this->name << " attacks with their " << (*this->type).getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &main_weapon)
{
    this->type = &main_weapon;
}