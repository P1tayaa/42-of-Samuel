#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    this->type = type;
    std::cout << "called Amateria Construct\n";
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

Ice::Ice(): AMateria("ice")
{
    std::cout << "called Ice Construct\n";
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria* Ice::clone() const
{
    AMateria* new_guy = new Ice(); 
    return (new_guy);
}

Cure::Cure(): AMateria("cure")
{
    std::cout << "called Cure Construct\n";
}

void Cure::use(ICharacter& target)
{
    std::cout << "* shoots an cure bolt at " << target.getName() << " *\n";
}

AMateria* Cure::clone() const
{
    AMateria* new_guy = new Cure(); 
    return (new_guy);
}
