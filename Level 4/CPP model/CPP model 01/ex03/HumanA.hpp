#include "Weapon.hpp"

class HumanA
{
	public:
    HumanA(std::string name, Weapon& main_weapon) : name(name), type(main_weapon) {};
	~HumanA() {};
	void	setWeapon(Weapon main_weapon);
	void	attack(void);
	
	private:
	std::string	name;
	Weapon&		type;
};