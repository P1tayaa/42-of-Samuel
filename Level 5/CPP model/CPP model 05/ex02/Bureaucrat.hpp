
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "GradeTooLowException.hpp"
class AForm;

class GradeTooHighException : public std::exception {
        public:
            virtual const char *what() const throw();
    };

class Bureaucrat
{
private:
    const   std::string _name;
    int     _grade;
public:
    GradeTooHighException GradeTooHigh;
    GradeTooLowException GradeTooLow;

    
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(Bureaucrat &dup);
    Bureaucrat  &operator=(const Bureaucrat &other);
    ~Bureaucrat();
    std::string get_name() const;
    int get_grade() const;
    void    increment_grade();
    void    decrement_grade();
    void    executeForm(AForm const & form);
};

std::ostream&   operator<<( std::ostream& o, const Bureaucrat& rhs );

#endif
