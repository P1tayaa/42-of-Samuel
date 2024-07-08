#ifndef SHRUBBERCREATIONFORM_HPP
# define SHRUBBERCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    void    execute_action(Bureaucrat const & executor) const;
public:
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
};


#endif