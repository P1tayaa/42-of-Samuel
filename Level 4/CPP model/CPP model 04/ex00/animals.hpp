#include <iostream>
#include <string>

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal
{
    public:
    Animal();
    virtual ~Animal();
    virtual std::string getType() const;
    virtual void        makeSound()  const;

    protected:
    std::string type;
};

class Dog : public Animal
{
    public:
    Dog();
    virtual ~Dog();
    void        makeSound() const;
};

class Cat : public Animal
{
    public:
    Cat();
    virtual ~Cat();
    void        makeSound() const;
};

#endif
