#include "Weapon.hpp"

class HumanB
{
	public:
	HumanB(std::string name) : name(name) {};
	~HumanB() {};
	void	setWeapon(Weapon &main_weapon);
	void	attack(void);

	private:
	std::string	name;
	Weapon*		type = NULL;
};