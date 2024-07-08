#ifndef GRADETOOLOWEXCEPTION_HPP
# define GRADETOOLOWEXCEPTION_HPP

# include <iostream>

class GradeTooLowException : public std::exception {
    public:
    virtual const char* what() const throw();
};

#endif
