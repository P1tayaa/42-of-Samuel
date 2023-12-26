#include "Weapon.hpp"

void		Weapon::setType(std::string new_type)
{
	this->type = new_type;
}

std::string	Weapon::getType(void)
{
	return (this->type);
}
