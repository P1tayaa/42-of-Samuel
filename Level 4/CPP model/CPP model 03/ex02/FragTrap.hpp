#include "ClapTrap.hpp"


#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap : public ClapTrap
{
    public:
    FragTrap(std::string name);
    ~FragTrap();
    void highFivesGuys(void);
};

#endif