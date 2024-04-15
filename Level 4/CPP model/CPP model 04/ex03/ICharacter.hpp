#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <iostream>
# include <string>
# include "AMateria.hpp"


class ICharacter
{
    public:
    ICharacter();
    virtual ~ICharacter();
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria    *inventory[4];
        AMateria    **lost_and_found;
        int         cur_inventory;
        int         cur_lost;
    public:
        Character(std::string name);
        ~Character();
        std::string const & getName() const;
        Character operator=(Character *new_charter);
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        Character& operator=(const Character& other);
};
#endif