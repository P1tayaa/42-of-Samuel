#include "Bureaucrat.h"


Bureaucrat::Bureaucrat(std::string new_name, int new_grade)
{
    this->name = new_name;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << this->name << " is dead\n";
}

std::string const Bureaucrat::getName() const
{
    return (this->name);
}

int const Bureaucrat::getGrade() const
{
    return (this->grade);
}
