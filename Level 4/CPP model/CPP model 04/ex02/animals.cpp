#include "animals.hpp"

Animal::Animal()
{
    this->type = "default";
    std::cout << "constructed an Animal\n";
}

Animal::~Animal()
{
    std::cout << "destructed an Animal\n";
}

std::string Animal::getType() const
{
    return (this->type);
}

void        Animal::makeSound() const
{
    std::cout << "BlaBla\n";
}

void        Dog::makeSound() const
{
    std::cout << "Bark\n";
}

Dog::Dog() : Animal()
{
    std::cout << "constructed an Dog\n";
    my_brain = new Brain();
    this->type = "Dog";
}

Dog::~Dog()
{
    delete my_brain;
    std::cout << "desstructed an Dog\n";
}

void        Cat::makeSound() const
{
    std::cout << "Miew\n";
}

Cat::Cat() : Animal()
{
    std::cout << "constructed an Cat\n";
    my_brain = new Brain();
    this->type = "Cat";
}

Cat::~Cat()
{
    delete my_brain;
    std::cout << "destructed an Cat\n";
}

Brain*      Cat::get_access_brain()
{
    return (my_brain);
}

Brain*      Dog::get_access_brain()
{
    return (my_brain);
}
