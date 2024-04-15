#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include <string>

class   ICharacter;

class AMateria
{
    protected:
    std::string type;
    public:
    AMateria(std::string const & type);
    // [...]
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};
# include "ICharacter.hpp"

class Ice: public AMateria
{
    public:
    Ice();
    ~Ice();
    void use(ICharacter& target);
    AMateria* clone() const;
};

class Cure: public AMateria
{
    public:
    Cure();
    ~Cure();
    void use(ICharacter& target);
    AMateria* clone() const;
};
#endif
