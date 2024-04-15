#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <iostream>
# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
    public:
    virtual ~IMateriaSource();
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
private:
    AMateria *slots[4];
public:
    MateriaSource(/* args */);
    ~MateriaSource();
    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);
};

#endif
