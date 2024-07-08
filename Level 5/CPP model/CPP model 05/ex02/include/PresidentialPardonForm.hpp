#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    void    execute_action(Bureaucrat const & executor) const;
public:
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
};


#endif