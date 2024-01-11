#include "wrongAnimal.hpp"


WrongAnimal::WrongAnimal()
{
    std::cout << "Wrong Animal Contstructor\n";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong Animal Destructor\n";
}

void    WrongAnimal::makeSound() const
{
    std::cout << "BlaBla\n";
}

WrongCat::WrongCat()
{
    std::cout << "Wrong cat Constructor\n";
}

WrongCat::~WrongCat()
{
    std::cout << "Wrong cat Destructor\n";
}
