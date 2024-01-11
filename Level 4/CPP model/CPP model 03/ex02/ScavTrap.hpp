#include "ClapTrap.hpp"

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP


class ScavTrap : public ClapTrap
{
    public:
    ScavTrap(std::string name);
    ~ScavTrap();
    void guardGate();
};

# endif
