
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
    Animal(const Animal &other);
    virtual Animal & operator = (const Animal &other);
    virtual std::string getType() const;
    virtual void        makeSound()  const;

    protected:
    std::string type;
};

class Dog : public Animal
{
    public:
    Dog();
    Dog(const Dog &other);
    Dog & operator = (const Dog &other);
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
    Cat(const Cat &other);
    Cat & operator = (const Cat &other);
    virtual ~Cat();
    void        makeSound() const;
    Brain*      get_access_brain();
    
    private:
    Brain* my_brain;
};

#endif
