#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <iostream>
# include <string.h>

class Bureaucrat
{
private:
    const std::string   name;
    int   grade;
public:
    Bureaucrat(std::string new_name, int new_grade);
    ~Bureaucrat();
    std::string const getName() const;
    int const getGrade() const;
};


#endif