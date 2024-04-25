
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
	ClapTrap(std::string name);
	~ClapTrap();
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	protected:
	std::string	name;
	int			hit_point = 10;
	int			energy_point = 10;
	int			attack_damage = 0;

};

# endif