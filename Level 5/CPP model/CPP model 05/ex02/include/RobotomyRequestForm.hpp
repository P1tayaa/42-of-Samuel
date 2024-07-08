#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    void    execute_action(Bureaucrat const & executor) const;
public:
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
};


#endif