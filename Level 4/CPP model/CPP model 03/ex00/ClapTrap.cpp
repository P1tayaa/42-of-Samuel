#include "ClapTrap.hpp"

    ClapTrap::ClapTrap(std::string name) : name(name)
    {
        std::cout << name << " ClapTrap constructor called\n";
    }

	ClapTrap::~ClapTrap()
    {
        std::cout << name << " ClapTrap destructor called\n";
    }

	void ClapTrap::attack(const std::string& target)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!\n";
    }

	void ClapTrap::takeDamage(unsigned int amount)
    {
        if (energy_point <= 0)
            return ;
        this->energy_point--;
        this->hit_point = this->hit_point - amount;
        std::cout << "ClapTrap " << this->name << " take " << amount << " damage, his current HP is " << this->hit_point << "!\n";
    }

	void ClapTrap::beRepaired(unsigned int amount)
    {
        if (energy_point <= 0)
            return ;
        this->energy_point--;
        this->hit_point = this->hit_point + amount;
        std::cout << "ClapTrap " << this->name << " is reparing himself by " << amount << " HP, his current HP is " << this->hit_point << "!\n";
    }