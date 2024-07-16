# pragma once

# include <iostream>
# include <string>
class AForm;

class Intern
{
public:
    Intern();
    Intern( const Intern& src );
    ~Intern();
    Intern& operator=( const Intern& rhs ); 
    AForm    *makeForm(std::string name, std::string target);
};