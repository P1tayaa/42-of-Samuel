#include <iostream>
#include <string>

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal
{
    public:
    Animal();
    virtual ~Animal();
    Animal(const Animal &other);
    Animal & operator = (const Animal &other);
    virtual std::string getType() const;
    virtual void        makeSound()  const;

    protected:
    std::string type;
};

class Dog : public Animal
{
    public:
    Dog();
    ~Dog();
    void        makeSound() const;
};

class Cat : public Animal
{
    public:
    Cat();
    ~Cat();
    void        makeSound() const;
};

#endif
