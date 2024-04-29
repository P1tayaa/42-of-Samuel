#include "wrongAnimal.hpp"


WrongAnimal::WrongAnimal()
{
    std::cout << "Wrong Animal Contstructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
    std::cout << "copy const called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this->type != other.type)
    {
        this->type = other.type;
    }
    std::cout << "assigne wronganimal called\n";
    return (*this);
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

void    WrongCat::makeSound() const
{
    std::cout << "Mious\n";
}

