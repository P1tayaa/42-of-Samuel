#include "IMateriaSource.hpp"

IMateriaSource::~IMateriaSource()
{
    std::cout << "IMateriaSource Deconstructor\n";
}

MateriaSource::MateriaSource(/* args */)
{
    std::cout << "MateriaSource constructor\n";
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource Deconstructor\n";
}

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{

}