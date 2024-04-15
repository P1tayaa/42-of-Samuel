#include "ICharacter.hpp"

ICharacter::ICharacter()
{
    std::cout << "Ichartater constructor called\n";
}

ICharacter::~ICharacter()
{
    std::cout << "Ichartater destructure called\n";
}


Character::Character(std::string name) : ICharacter()
{
    this->name = name;
    this->cur_inventory = 0;
    this->cur_lost = 0;
    std::cout << "called Character constructor\n";
}

Character::~Character()
{
    // delete this->inventory;
    delete this->lost_and_found;
    std::cout << "called Character destructor\n";
}

// void Character::equip(AMateria* m)
// {
//     if (cur_inventory < 4)
//         this->inventory[cur_inventory++] = m; 
//     else
//         this->lost_and_found[cur_lost++] = m;
// }

void Character::unequip(int idx)
{
    // for (int i = 0; i < cur_inventory; i++)
    // {
        this->lost_and_found[cur_lost++] = this->inventory[idx];
        this->inventory[idx] = NULL;
    // }
    cur_inventory = idx;
}

void Character::use(int idx, ICharacter& target)
{
    this->inventory[idx]->use(target);
}

std::string const & Character::getName() const
{
    return (this->name);
}

Character& Character::operator=(const Character& other)
{
    this->name = other.getName();
    return *this;
}

void Character::equip(AMateria* m)
{
    while (this->inventory[cur_inventory] != NULL && cur_inventory < 4)
    {
        cur_inventory++;
    }
    if (cur_inventory < 4)
    {
        this->inventory[cur_inventory] = m;
        cur_inventory++;
    }
}