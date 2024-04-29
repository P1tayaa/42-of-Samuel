#include <iostream>
#include <string>

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class WrongAnimal
{
    public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal & operator = (const WrongAnimal &other);
    virtual ~WrongAnimal();
    void        makeSound()  const;

    protected:
    std::string type;
};

class WrongCat : public WrongAnimal
{
    public:
    WrongCat();
    virtual ~WrongCat();
    void        makeSound() const;
};

#endif