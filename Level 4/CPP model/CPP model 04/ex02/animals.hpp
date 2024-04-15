
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "brain.hpp"

class Animal
{
    public:
    Animal();
    virtual ~Animal();
    virtual std::string getType() const;
    virtual void    makeSound()  const;

    protected:
    std::string type;
};

class Dog : public Animal
{
    public:
    Dog();
    virtual ~Dog();
    void        makeSound() const;
    Brain*      get_access_brain();
    
    private:
    Brain* my_brain;
};

class Cat : public Animal
{
    public:
    Cat();
    virtual ~Cat();
    void        makeSound() const;
    Brain*      get_access_brain();
    
    private:
    Brain* my_brain;
};

#endif
